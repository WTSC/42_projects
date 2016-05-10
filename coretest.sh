# **************************************************************************** #
#                                                                              #
#    coretest.sh                                                               #
#                                                                              #
#    By: egaborea <marvin@42.fr>                                               #
#                                                                              #
#    Created: 2016/03/29                                                       #
#                                                                              #
# **************************************************************************** #
#!/bin/bash

make -C ./asm

for fichier in `ls champions/*.s | cut -d . -f 1`
do
	./asm/asm $fichier.s
	mv $fichier.cor $fichier.our
	/sgoinfre/goinfre/corewar/asm $fichier.s
	mv $fichier.cor $fichier.ex
	diff $fichier.ex $fichier.our
	if [ $? -eq 0 ]
	then
		echo "OK !\t\t\t$fichier" >> out.txt
	else
		echo "NOT OK !\t\t$fichier" >> out.txt
#		echo `hexdump -vC $fichier.ex` >> error.txt
#		echo `hexdump -vC $fichier.our` >> error.txt
		diff $fichier.ex $fichier.our >> error.txt
		diff $fichier.ex $fichier.our 2>> error.txt
		echo "\n\n" >> error.txt

	fi
done


echo "\n\n"
cat out.txt
echo "\n\n"
rm -f *.txt
rm -f champions/*.our champions/*.ex
