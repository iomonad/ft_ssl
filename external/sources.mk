# file: sources.mk
#
# (c) iomonad <iomonad@riseup.net>
#
# This file is a part of the `ft_ssl`
# project, licensed under WTFPL.
#
# See: https://github.com/iomonad/ft_ssl/blob/master/LICENSE
#

MD5_PTH = md5/
MD5_FLS = hash.c
MD5_SRC = $(addprefix $(MD5_PTH), $(MD5_FLS))

SHA_PTH = sha/
SHA_FLS = sha256.c
SHA_SRC = $(addprefix $(SHA_PTH), $(SHA_FLS))

COMMONS_PTH = commons/
COMMONS_FLS = padding.c printer.c
COMMONS_SRC = $(addprefix $(COMMONS_PTH), $(COMMONS_FLS))

CRYPTO_PTH = crypto/
CRYPTO_SRC = $(addprefix $(CRYPTO_PTH), $(MD5_SRC)) \
             $(addprefix $(CRYPTO_PTH), $(COMMONS_SRC)) \
             $(addprefix $(CRYPTO_PTH), $(SHA_SRC))

ENGINE_PTH = engine/
ENGINE_FLS = core.c compute.c exceptions.c utils.c pipeline.c
ENGINE_SRC = $(addprefix $(ENGINE_PTH), $(ENGINE_FLS))

# Centralized resources
SRCS = $(ENGINE_SRC) $(CRYPTO_SRC)
