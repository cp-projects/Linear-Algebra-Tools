SUBDIRS = printLA/ errorsLA/ myArithmetic/ single_matrix_opps/ row_ops/ matrix_matrix/ vector_vector/ vector_vector/fast_vector_vector/ matrix_vector/ determinant/ elemination/

subdirs:
	for dir in $(SUBDIRS); do \
                $(MAKE) -C $$dir; \
        done

clean:
	for dir in $(SUBDIRS); do \
                $(MAKE) -C $$dir clean; \
        done

