# file: build.mk
#
# (c) iomonad <iomonad@riseup.net>
#
# This file is a part of the `ft_ssl`
# project, licensed under WTFPL.
#
# See: https://github.com/iomonad/ft_ssl/blob/master/LICENSE
#

TARGET = ft_ssl

all:
	$(MAKE) -C $(LFTDIR)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	$(MAKE) -C $(LFTDIR) fclean
	@rm -f $(TARGET)

fclean: clean

re: fclean
	$(MAKE)
