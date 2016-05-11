#!/bin/sh 
############################################################################
# File Name  : run_pc.sh
# Date       : 2015/11/30
# Author     : Yiqing Huang 
# Usage      : Name your producer executable as "produce" and put it in the
#              same directory where you put this shell script.
#              Type
#	       chomod 700 ./run_pc.sh
#              ./run_pc.sh 
#             
# Course Name: ECE254 Operating Systems and System Programming
# Description: Lab porject utility - extracting timing info.
#              The script assumes the following output format at stdout
#              from the producer process.
#  -------------------------------------------
#  <cid> <integer1> <perfect square root1> 
#  <cid> <integer2> <perfect square root2> 
#  ...
#  <cid> <integer3> <perfect square root3> 
#  System execution time: S seconds
#  -------------------------------------------
#  The script reads the last line where the timing info is and
#  then extract the S and output to a file. 
#  The outputfile naming convention is: N*_B*_P*_C*.dat.
#  The script then compute two tables:
#  tb1_$$.txt: average system execution time
#  tb2_$$.txt: standard deviation of system execution time
#  where $$ is the pid of process that executing this shell script.
#############################################################################
PROG="./produce"
N="100 398"
B="4 8"
P="1 2 3"
C="1 2 3"
X=500

exec_producer () 
{

	if [ $# != 6 ]; then
		echo "Usage: $0 <exec_name> <N> <B> <P> <C> <X>" 
		echo "  exec_name: executible's name"
		echo "  N: number of items to produce"
		echo "  B: buffer size"
		echo "  P: number of producers"
		echo "  C: number of consumers"
		echo "  X: number of times to run the executible for a given <N,B> pair "
		exit 1
	else
		PROGRAM=$1
		NUM2PRODUCE=$2
		BUFFER_SIZE=$3
		NUM_P=$4
		NUM_C=$5
		X_TIMES=$6
	fi

	O_FILE='N'${NUM2PRODUCE}'_B'${BUFFER_SIZE}'_P'${NUM_P}'_C'${NUM_C}'.dat'
	touch ${O_FILE}

	x=1
	while [ ${x} -le ${X_TIMES} ]
	do
		cmd="${PROGRAM} ${NUM2PRODUCE} ${BUFFER_SIZE} ${NUM_P} ${NUM_C}"
		str=`$cmd | tail -1 | awk -F: '{print $2}' | awk '{print $1}'`
		echo $str  >> ${O_FILE}
		x=`expr $x + 1`
	done
}

gen_data ()
{
	for n in $N
	do
		for b in $B
		do
			for p in $P
			do
				for c in $C
				do
					if [ $c == 1 ] || [ $p == 1 ]; then
						if !([ $n == 398 -a $b == 4 ]); then
							exec_producer $PROG $n $b $p $c $X
						fi
					fi
				done
			done
		done
	done
}

# directly writing each timing string to the tb files.
gen_stat_per_pair ()
{
	if [ $# != 1 ]; then
		echo "Usage: $0 <.dat file name>" 
		exit 1
	else
		FNAME_DATA=$1
	fi
	LIST="${FNAME_TB[1]} ${FNAME_TB[2]}"
	
	awk -v fname_tb_list="$LIST" '
	BEGIN{
		num_files = split(fname_tb_list, fname_tb, " ")
	}
	{
		sum[1]   += $1
		sumsq[1] += $1*$1  
	}
	END{
		for(i = 1; i <= num_files/2; i++) {
			printf("%.6lf\n", sum[i]/NR) >> fname_tb[2*i-1] 
			printf("%.6lf\n", sqrt(NR/(NR-1) * (sumsq[i]/NR - (sum[i]/NR)**2))) >> fname_tb[2*i]
		}
	} ' "${FNAME_DATA}"

}

gen_table ()
{
# assign table names
	NUM_TBS=2
	FNAME_TB[1]="tb1_$$.txt"
	FNAME_TB[2]="tb2_$$.txt"

# generate the table header
	i=1
	while [ ${i} -le ${NUM_TBS} ]
	do
		printf 'N\tB\tP\tC\tTime\n' >> ${FNAME_TB[${i}]} 
		i=`expr $i + 1`
	done

	for n in $N
	do
		for b in $B
		do
			for p in $P
			do
				for c in $C
				do
					if [ $c == 1 ] || [ $p == 1 ]; then
						if !([ $n == 398 -a $b == 4 ]); then
							i=1
							while [ ${i} -le ${NUM_TBS} ]
							do
								printf '%d\t%d\t%d\t%d\t' "$n" "$b" "$p" "$c" >> ${FNAME_TB[${i}]}
								i=`expr $i + 1`
							done
							FNAME_DATA="N${n}_B${b}_P${p}_C${c}.dat"
							echo $FNAME_DATA
							gen_stat_per_pair $FNAME_DATA
						fi
					fi
				done
			done
		done
	done
}

gen_data
gen_table
