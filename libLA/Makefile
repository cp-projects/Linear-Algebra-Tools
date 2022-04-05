SUBDIRS = printLA/ errorsLA/ myArithmetic/ single_matrix_opps/ row_opps/ matrix_matrix/ vector_vector/ matrix_vector/ determinant/ elemination/

subdirs:
	for dir in $(SUBDIRS); do \
                $(MAKE) -C $$dir; \
        done

clean:
	for dir in $(SUBDIRS); do \
                $(MAKE) -C $$dir clean; \
        done

