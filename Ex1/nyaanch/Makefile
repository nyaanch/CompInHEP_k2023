SRC = $(basename $(wildcard *.tex))

all:
	$(MAKE) -i tex
	$(MAKE) mf
	$(MAKE) tex
	$(MAKE) dvips

tex:
	latex $(SRC)

mf:
	mf "\mode=localfont; input Feynman_diagrams.mf;"

dvips:
	dvips $(SRC) -o

RM = $(sort $(wildcard *.dvi *.log *.aux Feynman_diagrams* *~))
clean:
	rm -r $(RM)

cleanAll:
	$(MAKE) clean
	rm -rf *.ps

test:
	echo $(SRC)