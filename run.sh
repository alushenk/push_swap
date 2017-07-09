MIN_INT=-2147483648;
MAX_INT=2147483647;

random_array () {
	python3 -c "import random; print(' '.join([str(x) for x in random.sample(range($MIN_INT, $MAX_INT), $COUNT)]))";
}

header () {
	WIDTH=$(tput cols);
	python3 -c "print('-' * $WIDTH)";
}

check () {
	RESULT="$(./push_swap $ARG | ./checker $ARG)";
	if [ "$RESULT" != "OK!" ]; then
		echo $MESSAGE
		echo $RESULT
		echo
	fi
}

check_wrong () {
	if [ "$RESULT" != "Error! Wrong arguments" ]; then
		echo $MESSAGE
		echo $RESULT
		echo
	fi
}

header

# at first check (by python?) if push_swap && checker exists, if not - check if Makefile exists, if so - make all

RESULT="$(./push_swap)";
if [ "$RESULT" != "Error! No arguments found" ]; then
	echo "no elements:"
	echo $RESULT
	echo
fi

RESULT="$(./checker)";
if [ "$RESULT" != "Error! No arguments found" ]; then
	echo "no elements:"
	echo $RESULT
	echo
fi

MESSAGE="one element:";
RESULT="$(./push_swap | ./checker 0)";
check_wrong

MESSAGE="one element:";
RESULT="$(./push_swap 1 2 3 a b | ./checker 1 2 3 a b )";
check_wrong

check_ko () {
	if [ "$RESULT" != "KO" ]; then
		echo $MESSAGE
		echo $RESULT
		echo
	fi
}

# checking for segfaults
echo "wrong commands to checker, should be KO!:"
echo "pa" | ./checker 3 2 1;
python3 -c "print('pa\n' * 10)" | ./checker 3 2 1;
python3 -c "print('pa\n' * 100)" | ./checker 3 2 1;
python3 -c "print('pa\n' * 1000)" | ./checker 3 2 1;
python3 -c "print('pa\n' * 10000)" | ./checker 3 2 1;

MESSAGE="suka nahuy";
ARG="-2 -5 -26 -7888 -564 -998 -12";
check

RESULT="$(./push_swap -2 -5 -26 -7888 -564 -998 -12 | ./checker -2 -5 -26 -7888 -998 -564 -12)";
check_ko

RESULT="$(./push_swap -5 -4 0 -7888 -564 -1 -12 | ./checker -2 -5 -26 -7888 -998 -564 -12)";
check_ko

RESULT="$(echo "ra ra pb pb pb pb ra sa rra rb pa rb pa sa pa pa" | ./checker -2 -5 -26 -7888 -998 -564 -12)";
check_ko

MESSAGE="two elements sorted:";
ARG="1 2";
check

MESSAGE="two elements unsorted:";
ARG="2 1";
check

MESSAGE="three elements sorted:";
ARG="1 2 3";
check

MESSAGE="three elements unsorted:";
ARG="3 2 1";
check

ARG="3 1 2";
check

ARG="1 3 2";
check

ARG="2 1 3";
check

MESSAGE="random 100:";
COUNT=100;
ARG=$(random_array);
check
ARG=$(random_array);
check
ARG=$(random_array);
check
ARG=$(random_array);
check
ARG=$(random_array);
check
ARG=$(random_array);
check
ARG=$(random_array);
check
ARG=$(random_array);
check

MESSAGE="random 500:";
COUNT=500;
ARG=$(random_array);
check
ARG=$(random_array);
check
ARG=$(random_array);
check
ARG=$(random_array);
check
ARG=$(random_array);
check
ARG=$(random_array);
check
ARG=$(random_array);
check

header