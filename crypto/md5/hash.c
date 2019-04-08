/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomonad <iomonad@riseup.net>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:33:05 by iomonad           #+#    #+#             */
/*   Updated: 2019/04/08 16:04:28 by iomonad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <engine.h>
#include <stdint.h>

/*
** Tableau de rotation determine par Ronald Rivest
** pour decrire les informations de decalage dans les
** etapes de hashing.
*/

static const	uint32_t g_r[] = {
	7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
	5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
	4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
	6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21
};

/*
** MD5 utilise des sinus d'entiers pour ses constantes
** Generation:
**
** `pour i de 0 à 63 faire
**     k[i] := floor(abs(sin(i + 1)) × 2^32)
**	fin pour`
*/

static const	uint32_t g_k[] = {
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

void			init_md5(t_hashing *hash)
{
	hash->state[0] = 0x67452301;
	hash->state[1] = 0xefcdab89;
	hash->state[2] = 0x98badcfe;
	hash->state[3] = 0x10325476;
	hash->dlen = 16;
	hash->clen = 64;
}

static int      left_rotate(uint32_t n, uint32_t d)
{
        return ((n << d) | (n >> (32 - d)));
}


static void swap_state(uint32_t f, uint32_t *tmp, uint32_t i)
{
	tmp[0] = tmp[3];
	tmp[3] = tmp[2];
	tmp[2] = tmp[1];
	tmp[1] += left_rotate(f, g_r[i]);
}

/*
** L'algorithme principal travaille avec un état sur 128 bits.
** Il est lui-même divisé en 4 mots de 32 bits (en informatique,
** on utilise le terme "mot" pour désigner une valeur de 32 bits
** ou "word" en anglais) : A, B, C et D.
** Ils sont initialisés au début avec des constantes.
** L'algorithme utilise ensuite les blocs provenant du message à hacher,
** ces blocs vont modifier l'état interne. Les opérations sur un bloc
** se décomposent en quatre rondes (étapes), elles-mêmes subdivisées
** en 16 opérations similaires basées sur une fonction non linéaire F
** qui varie selon la ronde, une addition et une rotation vers la gauche.
**
** Les quatre fonctions non linéaires disponibles sont:
**
** F(B,C,D) = (B\wedge{C}) \vee (\neg{B} \wedge{D}) ;
** G(B,C,D) = (B\wedge{D}) \vee (C \wedge \neg{D}) ;
** H(B,C,D) = B \oplus C \oplus D ;
** I(B,C,D) = C \oplus (B \vee \neg{D}).
*/

static void		hash_loop(uint32_t *tstate,
					  uint32_t *words,
					  uint32_t i)
{
	uint32_t	f;
	uint32_t	g;

	if (i <= 15)
	{
		f = (tstate[1] & tstate[2]) | (~tstate[1] & tstate[3]);
		g = i;
	}
	else if (i <= 31)
	{
		f = (tstate[3] & tstate[1]) | (~tstate[3] & tstate[2]);
		g = (5 * i + 1) % 16;
	}
	else if (i <= 47)
	{
		f = tstate[1] ^ tstate[2] ^ tstate[3];
		g = (3 * i + 5) % 16;
	}
	else
	{
		f = tstate[2] ^ (tstate[1] | ~tstate[3]);
		g = (7 * i) % 16;
	}
	f = f + tstate[0] + g_k[i] + words[g];
	swap_state(f, tstate, i);
}

void			md5_hash(t_hashing *hash, const char *chunk)
{
	uint32_t	*words;
	uint32_t	tstate[4];
	uint32_t	i;

	i = 0;
	ft_memcpy(tstate, hash->state, 4 * sizeof(uint32_t));
	words = (uint32_t *)chunk;
	while (++i < 64)
		hash_loop(tstate, words, i);
	i = 0;
	while (++i < 4)
		hash->state[i] += tstate[i];
}
