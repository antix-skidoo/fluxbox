# intercept the install stage so we can hack up some files

override_dh_auto_install_pre:
	dh_auto_install

override_dh_auto_install_clean:
	rm -f ./debian/fluxbox/usr/bin/fluxbox-generate_menu
	desktop-menu --write-out-global
	#	perl debian/update-init.pl \
	#		debian/fluxbox$(DEB_CONFIGURE_SYSCONFDIR)/init
	# FOR ANTIX, RUNNING DEBIAN'S update-init WOULD BE COUNTERPRODUCTIVE

override_dh_auto_install: \
	override_dh_auto_install_pre   \
	override_dh_auto_install_clean
