# Intercept the configure stage to throw it some flags.

DEB_CONFIGURE_EXTRA_FLAGS += -with-style=/usr/share/fluxbox/styles/redsy_dark

override_dh_auto_configure:
	./configure $(DEB_CONFIGURE_EXTRA_FLAGS)
