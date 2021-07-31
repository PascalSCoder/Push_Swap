echo "Instructions:"
python3 randomints.py && arg=$(<numbers.txt) && ./push_swap $arg | wc -l
echo "Codam checker:"
arg=$(<numbers.txt) && ./push_swap $arg | ./checker_linux $arg
echo "My checker:"
arg=$(<numbers.txt) && ./push_swap $arg | ./checker $arg
