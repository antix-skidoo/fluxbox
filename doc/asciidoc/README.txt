	=============
	preface (by skidoo):
	"xmlto" was not listed as a build dependency and is not currently installed on my system.
	"asciidoc" _is_ installed, but was not listed as a build-dep for fluxbox.
	I haven't tracked it down ~~ perhaps asciidoc was installed by "build-essential"

	I am just now, late in the game, finding the instruction "(to refresh the manpages) just run 'make dist' in this directory".
	Apparently-slash-obviously, "dpkg-buildpackage" is blind to this step
	(nothing in the /Debian subdir considers asciidoc)

	Debian 1.3.7 does not alter the manpages content provided by upstream.
	The fluxbox git repo used as my base contains already-generated *.in files for manpages
	WHICH ARE OUT-OF-SYNC  vs  MORE RECENTLY AMENDED FILES WITHIN THE /asciidoc subdirectory !    Grrrrrr....

	Yes, per the content of   /z/flux-ski/premake__1.3.8/doc/asciidoc/README.txt
	"xmlto" is required, is called by the "make dist" operation mentioned in this README, below.

	Upon installing xmlto, it also pulls in:   docbook-xsl    and    xsltproc   (16b total)
	These each installed docs (manpages, along with /usr/share/doc) which I haven't read.

	Attempting  `cd /z/flux-ski/premake__1.3.8/doc/asciidoc; make dist`   i NOTED:
	^---v
		1) displays warning re     Warn: AUTHOR sect.: blahblah
		2) DOES SUCCESSFULLY GENERATE *.in FILES IN THE PARENT DIRECTORY
		3) DOES SUCCESSFULLY CLEANUP ANY xml FILES GENERATED WHILE CONVERTING
		4) LEAVES "CRUFT" IN THE WORKING DIRECTORY  (a .1  or .5 file for each .txt file)...
		     which can (should) be removed by subsequently commanding  `make clean`

	=============



whats this? this is the attempt to write the documentation for
fluxbox in ascii-doc format. how does it work?

well, just edit fluxbox.txt from this directory. save it.
then we can produce pretty much any format we like: man, pdf, docbook, html, etc.

For simplicity, the Makefile here is set up to refresh the man pages that will be
installed with fluxbox.  Just run 'make dist' in this directory. It requires
that you have a recent asciidoc package installed from
http://www.methods.co.nz/asciidoc/ and xmlto from
https://fedorahosted.org/xmlto/browser.
The result will be new fluxbox.1.in files in the parent directory.
These, along with your altered .txt files, should be checked into git.

Here are the nuts and bolts to create other formats:

man:

  $> asciidoc -b docbook -d manpage fluxbox.txt
  $> xmlto man fluxbox.xml

pdf:

  $> asciidoc -b docbook -d manpage fluxbox.txt
  $> docbook2pdf fluxbox.xml

docbook:

  $> asciidoc -b docbook-sgml -d manpage fluxbox.txt

html:

  $> asciidoc -b xhtml -d manpage fluxbox.txt

and many many more ways to do it.
What do we need? well, at least:

  http://www.methods.co.nz/asciidoc/
  http://cyberelk.net/tim/xmlto/

and the rest of the docbook-family + maybe pdftex.
