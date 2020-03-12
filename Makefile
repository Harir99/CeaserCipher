all:frequency_table decode copy_record

frequency_table:frequency_table.o  file_size.o letter_count.o print_frequency_table.o remove_spaces.o Frequency_table.o chars_count.o replace_punc.o chop.o
	gcc -Wall  -o frequency_table frequency_table.o file_size.o letter_count.o print_frequency_table.o remove_spaces.o Frequency_table.o chars_count.o replace_punc.o chop.o

decode:decode.o Text_freq.o encode.o letter_count.o offset.o file_size.o read_file.o get_ch_sq.o encode_shift.o to_decode.o malloc_new_file.o remove_spaces.o replace_punc.o chop.o numbers_shifting.o
	gcc -Wall -o decode decode.o Text_freq.o encode.o letter_count.o offset.o file_size.o read_file.o get_ch_sq.o encode_shift.o to_decode.o malloc_new_file.o remove_spaces.o replace_punc.o chop.o numbers_shifting.o

copy_record:copy_record.o add_first.o listToFile.o get_num_entries.o fileToList.o Text_freq.o encode.o letter_count.o offset.o file_size.o read_file.o get_ch_sq.o encode_shift.o to_decode.o malloc_new_file.o remove_spaces.o replace_punc.o chop.o numbers_shifting.o
	gcc -Wall -o  copy_record copy_record.o add_first.o listToFile.o get_num_entries.o fileToList.o Text_freq.o encode.o letter_count.o offset.o file_size.o read_file.o get_ch_sq.o encode_shift.o to_decode.o malloc_new_file.o remove_spaces.o replace_punc.o chop.o numbers_shifting.o -lm

file_size:file_size.c
	gcc -Wall  -c file_size.c

letter_count:letter_count.c
	gcc -Wall  -c letter_count.c

print_frequency_table:print_frequency_table.c
	gcc -Wall  -c print_frequency_table.c

chars_count:chars_count.c
	gcc -Wall  -c chars_count.c

Frequency_table:Frequency_table.c
	gcc -Wall  -c Frequency_table.c

remove_spaces:remove_spaces.c
	gcc -Wall  -c remove_spaces.c

Text_freq:Text_freq.c
	gcc -Wall  -c Text_freq.c

encode:encode.c
	gcc -Wall  -c encode.c

offset:offset.c
	gcc -Wall  -c offset.c

read_file:read_file.c
	gcc -Wall  -c read_file.c

get_ch_sq: get_ch_sq.c
	gcc -Wall -c get_ch_sq.c

encode_shift:encode_shift.c
	gcc -Wall  -c encode_shift.c

malloc_new_file:malloc_new_file.c
	gcc -Wall -c malloc_new_file.c

replace_punc:replace_punc.c
	gcc -Wall -c replace_punc.c

chop:chop.c
	gcc -Wall -c chop chop.c

numbers_shifting:numbers_shifting.c
	gcc -Wall -c numbers_shifting.c

add_first:add_first.c
	gcc -Wall -c add_first.c

listToFile:listToFile.c
	gcc -Wall -c listToFile.c

get_num_entries:get_num_entries.c
	gcc -Wall -c get_num_entries.c

FileTolist:FileTolist.c
	gcc -Wall -c FileTolist.c
	
to_decode:to_decode.c
	gcc -Wall -c to_decode.c

clean:
	rm -rf *.o
	rm -rf frequency_table
	rm -rf decode
	rm -rf copy_record
