SHELL = /bin/sh
.SUFFIXES:
.SUFFIXES: .c .o

PREFIX ?= /usr
BINDIR  ?= $(PREFIX)/bin
LIBDIR  ?= $(PREFIX)/lib
INCDIR  ?= /usr/include

INSTALL = install
INSTALL_PROGRAM = $(INSTALL) -m 755
INSTALL_DATA = $(INSTALL) -m 644

CC      = gcc
CFLAGS  = -Wall -Wextra -O2 -I$(INCDIR) -D_GNU_SOURCE
LDFLAGS = -L$(LIBDIR) -llazybios

TARGET = lazydmi
SRCS   = lazydmi.c
OBJS   = $(SRCS:.c=.o)

.PHONY: all clean install uninstall distclean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

distclean: clean

install: $(TARGET)
	mkdir -p $(DESTDIR)$(BINDIR)
	$(INSTALL_PROGRAM) $(TARGET) $(DESTDIR)$(BINDIR)/$(TARGET)

uninstall:
	rm -f $(DESTDIR)$(BINDIR)/$(TARGET)
