# file: system.mk
#
# (c) iomonad <iomonad@riseup.net>
#
# This file is a part of the `ft_ssl`
# project, licensed under WTFPL.
#
# See: https://github.com/iomonad/ft_ssl/blob/master/LICENSE
#

# Compilation
AARCH := $(shell uname -s)
ifeq ($(AARCH), Linux)
	CC = gcc
else
	CC = clang
endif
LD = ld
CFLAGS = -Wall -Werror -Wextra -O2 $(IFLAGS)
IFLAGS = -I$(INCDIR)
NPROC = $(shell sysctl -n hw.physicalcpu)
MAKEFLAGS += --silent -k -j$(NPROC) --no-print-directory

# Nomenclature
INCDIR = includes/
vpath %.h $(INCDIR)
