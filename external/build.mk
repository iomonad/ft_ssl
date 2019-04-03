# file: build.mk
#
# (c) iomonad <iomonad@riseup.net>
#
# This file is a part of the `ft_ssl`
# project, licensed under WTFPL.
#
# See: https://github.com/iomonad/ft_ssl/blob/master/LICENSE
#

BIN = ft_ssl

all:
	@touch $(BIN)

clean:
	@rm -f $(BIN)

fclean: clean

re: fclean
	$(MAKE)
