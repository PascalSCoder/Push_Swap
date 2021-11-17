make all -C ../
clear

if [ $# -eq 0 ]; then
	python3 randomints.py
else
	python3 randomints.py $1
fi

echo "Instruction count:"
arg=$(<numbers.txt) && ../push_swap $arg | wc -l
echo "Supplied checker:"
if [[ "$OSTYPE" == "darwin"* ]]; then
	arg=$(<numbers.txt) && ../push_swap $arg | ./checker_mac $arg
else
	arg=$(<numbers.txt) && ../push_swap $arg | ./checker_linux $arg
fi
echo "Custom checker:"
arg=$(<numbers.txt) && ../push_swap $arg | ../checker $arg
