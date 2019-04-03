# file: sources.mk
#
# (c) iomonad <iomonad@riseup.net>
#
# This file is a part of the `ft_ssl`
# project, licensed under WTFPL.
#
# See: https://github.com/iomonad/ft_ssl/blob/master/LICENSE
#

#
CRYPTO_SRC =

ENGINE_PTH = engine/
ENGINE_FLS = core.c
ENGINE_SRC = $(addsuffix $(ENGINE_FLS), $(ENGINE_PTH))

# Centralized resources
SRCS = $(ENGINE_SRC) $(CRYPTO_SRC)
