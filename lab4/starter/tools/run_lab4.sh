#!/bin/sh 
############################################################################
# File Name  : run_lab4.sh
# Date       : June 25 2014
# Author     : Yiqing Huang 
# Usage      : Name your producer executable as "produce" and put it in the
#              same directory where you put this shell script.
#              Type
#
#              chmod 700 ./run_lab4.sh
#              ./run_lab4.sh 
#             
# Course Name: ECE254 Operating Systems and System Programming
# Description: Lab4 utility - extracting timing info.
#              The script assumes the following output format at stdout
#              from the producer process.
#  -------------------------------------------
#  random num 1
#  random num 2
#  ...
#  random num N
#  Time to initialize system: S1 seconds
#  Time to transmit data: S2 seconds
#  -------------------------------------------
#  The script reads the last two lines where the timing info is and
#  then extract the S1 and S2 and output "S1 S2" in a line in the 
#  outputfile N*_B*.dat.
#  The script then compute for tables.
#  tb1_$$.txt: average system initialization time
#  tb2_$$.txt: standard deviation of system initialization time
#  tb3_$$.txt: average data transmission time
#  tb4_$$.txt: standard deviation of the data transmission time,
#  where $$ is the pid of process that executing this shell script.
#############################################################################
PROG="./produce"
N="20 40 80 160 320"
B="1 2 4 8 10"
X=500

exec_producer () 
{

	if [ $# != 4 ]; then
		echo "Usage: $0 <exec_name> <N> <B> <X>" 
		echo "  exec_name: executible's name"
		echo "  N: number of items to produce"
		echo "  B: buffer size"
		echo "  X: number of times to run the executible for a given <N,B> pair "
		exit 1
	else
		PROGRAM=$1
		NUM2PRODUCE=$2
		BUFFER_SIZE=$3
		X_TIMES=$4
	fi

	O_FILE='N'${NUM2PRODUCE}'_B'${BUFFER_SIZE}'.dat'
	touch ${O_FILE}

	x=1
	while [ ${x} -le ${X_TIMES} ]
	do
		cmd="${PROGRAM} ${NUM2PRODUCE} ${BUFFER_SIZE}"
		str=`$cmd | tail -2 | awk -F: '{print $2}' | awk '{print $1}'`
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
			exec_producer $PROG $n $b $X
		done
	done
}

# return a string: 
# avg_init_time stdev_init_time  avg_trans_time  stdev_trans_time
# directly writing each token in string to the tb files
gen_stat_per_pair ()
{
	if [ $# != 1 ]; then
		echo "Usage: $0 <.dat file name>" 
		exit 1
	else
		FNAME_DATA=$1
	fi
	LIST="${FNAME_TB[1]} ${FNAME_TB[2]} ${FNAME_TB[3]} ${FNAME_TB[4]}"
	
	awk -v fname_tb_list="$LIST" '
	BEGIN{
		num_files = split(fname_tb_list, fname_tb, " ")
	}
	{
		sum[1]   += $1
		sum[2]   += $2  
		sumsq[1] += $1*$1  
		sumsq[2] += $2*$2
	}
	END{
		for(i = 1; i <= num_files/2; i++) {
			printf("\t%.6lf", sum[i]/NR) >> fname_tb[2*i-1] 
			printf("\t%.6lf", sqrt(NR/(NR-1) * (sumsq[i]/NR - (sum[i]/NR)**2))) >> fname_tb[2*i]
		}
	} ' "${FNAME_DATA}"

}

gen_table ()
{
# assign table names
	NUM_TBS=4
	FNAME_TB[1]="tb1_$$.txt"
	FNAME_TB[2]="tb2_$$.txt"
	FNAME_TB[3]="tb3_$$.txt"
	FNAME_TB[4]="tb4_$$.txt"

# generate the table header
	i=1
	while [ ${i} -le ${NUM_TBS} ]
	do
		printf 'N\B' >> ${FNAME_TB[${i}]} 
		for b in $B
		do
			printf '\t%8d' "$b"  >> ${FNAME_TB[${i}]} 
		done
		printf '\n' >> ${FNAME_TB[${i}]}
		i=`expr $i + 1`
	done

# compute the stat for each entry in the table
	for n in $N
	do
		i=1
		while [ ${i} -le ${NUM_TBS} ]
		do
			printf '%8d' "$n" >> ${FNAME_TB[${i}]}
			i=`expr $i + 1`
		done

		for b in $B
		do
			FNAME_DATA="N${n}_B${b}.dat"
			# use awk to compute stat
			gen_stat_per_pair $FNAME_DATA
		done

		#adding newline at the end of each file
		i=1
		while [ ${i} -le ${NUM_TBS} ]
		do
			printf '\n' >> ${FNAME_TB[${i}]}
			i=`expr $i + 1`
		done
	done
}

gen_data
gen_table
