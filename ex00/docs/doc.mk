RM				=	rm -rf

HTML_DIR		=	html/
LATEX_DIR		=	latex/

DOXYFILE_PATH	= Doxyfile
INDEX_HTML_PATH	= $(HTML_DIR)index.html

doc:
	@ if [ ! -f $(DOXYFILE_PATH) ]; then doxygen -g $(DOXYFILE_PATH); fi
	@ doxygen $(DOXYFILE_PATH)
	@ open $(INDEX_HTML_PATH)

fclean:
	$(RM) $(HTML_DIR) $(LATEX_DIR)

.PHONY:	doc fclean
