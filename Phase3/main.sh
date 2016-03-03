#!/bin/bash

#lots of repetition, but will abstract into 1 method and clean up later (maybe)

function loginlogout { 
	#! testing login and logout
	echo -e "\e[104mTesting login and logout...\e[0m"
	cd 0_loginlogout

	num="$(ls *.in -1 | wc -l)"

	opass=0
	ofail=0
	tpass=0
	tfail=0
	#./output 0_loginlogout/01_loginlogout_std_session.in results/$timestamp/0_loginlogout/01_loginlogout_std_session.testTrans
	echo "SUMMARY OF LOGIN/LOGOUT FOR $timestamp" >> ../results/$timestamp/0_loginlogout.summary
	for ((i=1; i <= $num; i++))
	do

		echo -e "\e[95mRunning test $i\e[0m"
		num2="$(ls 0$i\_*.in)"
		#echo "${num2}"
		cd ../
		./quit.sh & ./output 0_loginlogout/${num2} results/$timestamp/0_loginlogout/$i.trans > results/$timestamp/0_loginlogout/$i.out
		#sh -x ./quit.sh & ./output 0_loginlogout/${num2} results/$timestamp/0_loginlogout/$i.testTrans
		# script cannot progress because c++ program doesnt terminate... 
		
		cd 0_loginlogout
		num3="$(ls 0$i\_*.out)"
		#echo -e "Checking output for test $i:"
		DIFF=$(diff ${num3} ../results/$timestamp/0_loginlogout/$i.out) 

		if [ "$DIFF" != "" ] 
		then
			echo -e "\e[41mTEST ${num3} OUTPUT FAILED.\e[0m" 
			echo "TEST ${num3} OUTPUT FAILED." >> ../results/$timestamp/0_loginlogout.summary
			ofail=$[ofail+1]
		else 
			echo -e "\e[42mTEST ${num3} OUTPUT PASSED.\e[0m" 
			echo "TEST ${num3} OUTPUT PASSED." >> ../results/$timestamp/0_loginlogout.summary
			opass=$[opass+1]
		fi
		num4="$(ls 0$i\_*.trans)"
		DIFF2=$(diff ${num4} ../results/$timestamp/0_loginlogout/$i.trans) 
		if [ "$DIFF2" != "" ] 
		then
			echo -e "\e[41mTEST ${num4} TRANSACTION FAILED.\e[0m" 
			echo "TEST ${num4} TRANSACTION FAILED." >> ../results/$timestamp/0_loginlogout.summary
			tfail=$[tfail+1]
		else 
			echo -e "\e[42mTEST ${num4} TRANSACTION PASSED.\e[0m"
			echo "TEST ${num4} OUTPUT PASSED." >> ../results/$timestamp/0_loginlogout.summary
			tpass=$[tpass+1]
		fi
		#./output 0_loginlogout/01_loginlogout_std_session.in results/$timestamp/0_loginlogout/01_loginlogout_std_session.testTrans
	done


	cd ../
	echo -e "\e[45mLogin and logout test completed.\e[0m"
	echo -e "\e[45mOUTPUT PASSED: $opass/$num\e[0m"
	echo -e "\e[45mOUTPUT FAILED: $ofail/$num\e[0m"
	echo -e "\e[45mTRANS PASSED: $tpass/$num\e[0m"
	echo -e "\e[45mTRANS FAILED: $tfail/$num\e[0m"
}

function withdrawal { 
	#! testing withdrawal
	
	echo -e "\e[0m-------------------------------\e[0m"
	echo -e "\e[104mTesting withdrawal...\e[0m"
	cd 1_withdrawal

	num="$(ls *.in -1 | wc -l)"

	opass=0
	ofail=0
	tpass=0
	tfail=0
	#./output 1_withdrawal/01_loginlogout_std_session.in results/$timestamp/1_withdrawal/01_loginlogout_std_session.testTrans
	echo "SUMMARY OF WITHDRAWAL FOR $timestamp" >> ../results/$timestamp/1_withdrawal.summary
	for ((i=1; i <= $num; i++))
	do

		echo -e "\e[95mRunning test $i\e[0m"
		num2="$(ls 0$i\_*.in)"
		#echo "${num2}"
		cd ../
		./quit.sh & ./output 1_withdrawal/${num2} results/$timestamp/1_withdrawal/$i.trans > results/$timestamp/1_withdrawal/$i.out
		#sh -x ./quit.sh & ./output 1_withdrawal/${num2} results/$timestamp/1_withdrawal/$i.testTrans
		# script cannot progress because c++ program doesnt terminate... 
		
		cd 1_withdrawal
		num3="$(ls 0$i\_*.out)"
		#echo -e "Checking output for test $i:"
		DIFF=$(diff ${num3} ../results/$timestamp/1_withdrawal/$i.out) 

		if [ "$DIFF" != "" ] 
		then
			echo -e "\e[41mTEST ${num3} OUTPUT FAILED.\e[0m" 
			echo "TEST ${num3} OUTPUT FAILED." >> ../results/$timestamp/1_withdrawal.summary
			ofail=$[ofail+1]
		else 
			echo -e "\e[42mTEST ${num3} OUTPUT PASSED.\e[0m" 
			echo "TEST ${num3} OUTPUT PASSED." >> ../results/$timestamp/1_withdrawal.summary
			opass=$[opass+1]
		fi
		num4="$(ls 0$i\_*.trans)"
		DIFF2=$(diff ${num4} ../results/$timestamp/1_withdrawal/$i.trans) 
		if [ "$DIFF2" != "" ] 
		then
			echo -e "\e[41mTEST ${num4} TRANSACTION FAILED.\e[0m" 
			echo "TEST ${num4} TRANSACTION FAILED." >> ../results/$timestamp/1_withdrawal.summary
			tfail=$[tfail+1]
		else 
			echo -e "\e[42mTEST ${num4} TRANSACTION PASSED.\e[0m"
			echo "TEST ${num4} OUTPUT PASSED." >> ../results/$timestamp/1_withdrawal.summary
			tpass=$[tpass+1]
		fi
		#./output 1_withdrawal/01_loginlogout_std_session.in results/$timestamp/1_withdrawal/01_loginlogout_std_session.testTrans
	done


	cd ../
	
	echo -e "\e[45mWithdrawal test completed.\e[0m"	
	echo -e "\e[45mOUTPUT PASSED: $opass/$num\e[0m"
	echo -e "\e[45mOUTPUT FAILED: $ofail/$num\e[0m"
	echo -e "\e[45mTRANS PASSED: $tpass/$num\e[0m"
	echo -e "\e[45mTRANS FAILED: $tfail/$num\e[0m"
}

function transfer { 
	#! testing transfer

	echo -e "\e[0m-------------------------------\e[0m"
	echo -e "\e[104mTesting transfer...\e[0m"

	cd 2_transfer

	num="$(ls *.in -1 | wc -l)"

	opass=0
	ofail=0
	tpass=0
	tfail=0
	#./output 2_transfer/01_loginlogout_std_session.in results/$timestamp/2_transfer/01_loginlogout_std_session.testTrans
	echo "SUMMARY OF TRANSFER FOR $timestamp" >> ../results/$timestamp/2_transfer.summary
	for ((i=1; i <= $num; i++))
	do

		echo -e "\e[95mRunning test $i\e[0m"
		num2="$(ls 0$i\_*.in)"
		#echo "${num2}"
		cd ../
		./quit.sh & ./output 2_transfer/${num2} results/$timestamp/2_transfer/$i.trans > results/$timestamp/2_transfer/$i.out
		#sh -x ./quit.sh & ./output 2_transfer/${num2} results/$timestamp/2_transfer/$i.testTrans
		# script cannot progress because c++ program doesnt terminate... 
		
		cd 2_transfer
		num3="$(ls 0$i\_*.out)"
		#echo -e "Checking output for test $i:"
		DIFF=$(diff ${num3} ../results/$timestamp/2_transfer/$i.out) 

		if [ "$DIFF" != "" ] 
		then
			echo -e "\e[41mTEST ${num3} OUTPUT FAILED.\e[0m" 
			echo "TEST ${num3} OUTPUT FAILED." >> ../results/$timestamp/2_transfer.summary
			ofail=$[ofail+1]
		else 
			echo -e "\e[42mTEST ${num3} OUTPUT PASSED.\e[0m" 
			echo "TEST ${num3} OUTPUT PASSED." >> ../results/$timestamp/2_transfer.summary
			opass=$[opass+1]
		fi
		num4="$(ls 0$i\_*.trans)"
		DIFF2=$(diff ${num4} ../results/$timestamp/2_transfer/$i.trans) 
		if [ "$DIFF2" != "" ] 
		then
			echo -e "\e[41mTEST ${num4} TRANSACTION FAILED.\e[0m" 
			echo "TEST ${num4} TRANSACTION FAILED." >> ../results/$timestamp/2_transfer.summary
			tfail=$[tfail+1]
		else 
			echo -e "\e[42mTEST ${num4} TRANSACTION PASSED.\e[0m"
			echo "TEST ${num4} OUTPUT PASSED." >> ../results/$timestamp/2_transfer.summary
			tpass=$[tpass+1]
		fi
		#./output 2_transfer/01_loginlogout_std_session.in results/$timestamp/2_transfer/01_loginlogout_std_session.testTrans
	done




	cd ../
	
	echo -e "\e[45mTransfer test completed.\e[0m"
	echo -e "\e[45mOUTPUT PASSED: $opass/$num\e[0m"
	echo -e "\e[45mOUTPUT FAILED: $ofail/$num\e[0m"
	echo -e "\e[45mTRANS PASSED: $tpass/$num\e[0m"
	echo -e "\e[45mTRANS FAILED: $tfail/$num\e[0m"
}


function paybill { 
	#! testing paybill
	echo -e "\e[0m-------------------------------\e[0m"
	echo -e "\e[104mTesting paybill...\e[0m"
	
	cd 3_paybill

	num="$(ls *.in -1 | wc -l)"

	opass=0
	ofail=0
	tpass=0
	tfail=0
	#./output 3_paybill/01_loginlogout_std_session.in results/$timestamp/3_paybill/01_loginlogout_std_session.testTrans
	echo "SUMMARY OF PAYBILL FOR $timestamp" >> ../results/$timestamp/3_paybill.summary
	for ((i=1; i <= $num; i++))
	do

		echo -e "\e[95mRunning test $i\e[0m"
		num2="$(ls 0$i\_*.in)"
		#echo "${num2}"
		cd ../
		./quit.sh & ./output 3_paybill/${num2} results/$timestamp/3_paybill/$i.trans > results/$timestamp/3_paybill/$i.out
		#sh -x ./quit.sh & ./output 3_paybill/${num2} results/$timestamp/3_paybill/$i.testTrans
		# script cannot progress because c++ program doesnt terminate... 
		
		cd 3_paybill
		num3="$(ls 0$i\_*.out)"
		#echo -e "Checking output for test $i:"
		DIFF=$(diff ${num3} ../results/$timestamp/3_paybill/$i.out) 

		if [ "$DIFF" != "" ] 
		then
			echo -e "\e[41mTEST ${num3} OUTPUT FAILED.\e[0m" 
			echo "TEST ${num3} OUTPUT FAILED." >> ../results/$timestamp/3_paybill.summary
			ofail=$[ofail+1]
		else 
			echo -e "\e[42mTEST ${num3} OUTPUT PASSED.\e[0m" 
			echo "TEST ${num3} OUTPUT PASSED." >> ../results/$timestamp/3_paybill.summary
			opass=$[opass+1]
		fi
		num4="$(ls 0$i\_*.trans)"
		DIFF2=$(diff ${num4} ../results/$timestamp/3_paybill/$i.trans) 
		if [ "$DIFF2" != "" ] 
		then
			echo -e "\e[41mTEST ${num4} TRANSACTION FAILED.\e[0m" 
			echo "TEST ${num4} TRANSACTION FAILED." >> ../results/$timestamp/3_paybill.summary
			tfail=$[tfail+1]
		else 
			echo -e "\e[42mTEST ${num4} TRANSACTION PASSED.\e[0m"
			echo "TEST ${num4} OUTPUT PASSED." >> ../results/$timestamp/3_paybill.summary
			tpass=$[tpass+1]
		fi
		#./output 3_paybill/01_loginlogout_std_session.in results/$timestamp/3_paybill/01_loginlogout_std_session.testTrans
	done

	cd ../
	echo -e "\e[45mPaybill test completed.\e[0m"
	echo -e "\e[45mOUTPUT PASSED: $opass/$num\e[0m"
	echo -e "\e[45mOUTPUT FAILED: $ofail/$num\e[0m"
	echo -e "\e[45mTRANS PASSED: $tpass/$num\e[0m"
	echo -e "\e[45mTRANS FAILED: $tfail/$num\e[0m"
}

function deposit { 
	#! testing deposit
	echo -e "\e[0m-------------------------------\e[0m"
	echo -e "\e[104mTesting deposit...\e[0m"
	cd 4_deposit

	num="$(ls *.in -1 | wc -l)"

	opass=0
	ofail=0
	tpass=0
	tfail=0
	#./output 4_deposit/01_loginlogout_std_session.in results/$timestamp/4_deposit/01_loginlogout_std_session.testTrans
	echo "SUMMARY OF DEPOSIT FOR $timestamp" >> ../results/$timestamp/4_deposit.summary
	for ((i=1; i <= $num; i++))
	do

		echo -e "\e[95mRunning test $i\e[0m"
		num2="$(ls 0$i\_*.in)"
		#echo "${num2}"
		cd ../
		./quit.sh & ./output 4_deposit/${num2} results/$timestamp/4_deposit/$i.trans > results/$timestamp/4_deposit/$i.out
		#sh -x ./quit.sh & ./output 4_deposit/${num2} results/$timestamp/4_deposit/$i.testTrans
		# script cannot progress because c++ program doesnt terminate... 
		
		cd 4_deposit
		num3="$(ls 0$i\_*.out)"
		#echo -e "Checking output for test $i:"
		DIFF=$(diff ${num3} ../results/$timestamp/4_deposit/$i.out) 

		if [ "$DIFF" != "" ] 
		then
			echo -e "\e[41mTEST ${num3} OUTPUT FAILED.\e[0m" 
			echo "TEST ${num3} OUTPUT FAILED." >> ../results/$timestamp/4_deposit.summary
			ofail=$[ofail+1]
		else 
			echo -e "\e[42mTEST ${num3} OUTPUT PASSED.\e[0m" 
			echo "TEST ${num3} OUTPUT PASSED." >> ../results/$timestamp/4_deposit.summary
			opass=$[opass+1]
		fi
		num4="$(ls 0$i\_*.trans)"
		DIFF2=$(diff ${num4} ../results/$timestamp/4_deposit/$i.trans) 
		if [ "$DIFF2" != "" ] 
		then
			echo -e "\e[41mTEST ${num4} TRANSACTION FAILED.\e[0m" 
			echo "TEST ${num4} TRANSACTION FAILED." >> ../results/$timestamp/4_deposit.summary
			tfail=$[tfail+1]
		else 
			echo -e "\e[42mTEST ${num4} TRANSACTION PASSED.\e[0m"
			echo "TEST ${num4} OUTPUT PASSED." >> ../results/$timestamp/4_deposit.summary
			tpass=$[tpass+1]
		fi
		#./output 4_deposit/01_loginlogout_std_session.in results/$timestamp/4_deposit/01_loginlogout_std_session.testTrans
	done

	cd ../

	echo -e "\e[45mDeposit test completed.\e[0m"
	echo -e "\e[45mOUTPUT PASSED: $opass/$num\e[0m"
	echo -e "\e[45mOUTPUT FAILED: $ofail/$num\e[0m"
	echo -e "\e[45mTRANS PASSED: $tpass/$num\e[0m"
	echo -e "\e[45mTRANS FAILED: $tfail/$num\e[0m"
}


function create { 
	#! testing create
	echo -e "\e[0m-------------------------------\e[0m"
	echo -e "\e[104mTesting create...\e[0m"
	cd 5_create

	num="$(ls *.in -1 | wc -l)"

	opass=0
	ofail=0
	tpass=0
	tfail=0
	#./output 5_create/01_loginlogout_std_session.in results/$timestamp/5_create/01_loginlogout_std_session.testTrans
	echo "SUMMARY OF CREATE FOR $timestamp" >> ../results/$timestamp/5_create.summary
	for ((i=1; i <= $num; i++))
	do

		echo -e "\e[95mRunning test $i\e[0m"
		num2="$(ls 0$i\_*.in)"
		#echo "${num2}"
		cd ../
		./quit.sh & ./output 5_create/${num2} results/$timestamp/5_create/$i.trans > results/$timestamp/5_create/$i.out
		#sh -x ./quit.sh & ./output 5_create/${num2} results/$timestamp/5_create/$i.testTrans
		# script cannot progress because c++ program doesnt terminate... 
		
		cd 5_create
		num3="$(ls 0$i\_*.out)"
		#echo -e "Checking output for test $i:"
		DIFF=$(diff ${num3} ../results/$timestamp/5_create/$i.out) 

		if [ "$DIFF" != "" ] 
		then
			echo -e "\e[41mTEST ${num3} OUTPUT FAILED.\e[0m" 
			echo "TEST ${num3} OUTPUT FAILED." >> ../results/$timestamp/5_create.summary
			ofail=$[ofail+1]
		else 
			echo -e "\e[42mTEST ${num3} OUTPUT PASSED.\e[0m" 
			echo "TEST ${num3} OUTPUT PASSED." >> ../results/$timestamp/5_create.summary
			opass=$[opass+1]
		fi
		num4="$(ls 0$i\_*.trans)"
		DIFF2=$(diff ${num4} ../results/$timestamp/5_create/$i.trans) 
		if [ "$DIFF2" != "" ] 
		then
			echo -e "\e[41mTEST ${num4} TRANSACTION FAILED.\e[0m" 
			echo "TEST ${num4} TRANSACTION FAILED." >> ../results/$timestamp/5_create.summary
			tfail=$[tfail+1]
		else 
			echo -e "\e[42mTEST ${num4} TRANSACTION PASSED.\e[0m"
			echo "TEST ${num4} OUTPUT PASSED." >> ../results/$timestamp/5_create.summary
			tpass=$[tpass+1]
		fi
		#./output 5_create/01_loginlogout_std_session.in results/$timestamp/5_create/01_loginlogout_std_session.testTrans
	done


	cd ../
	echo -e "\e[45mCreate test completed.\e[0m"
	echo -e "\e[45mOUTPUT PASSED: $opass/$num\e[0m"
	echo -e "\e[45mOUTPUT FAILED: $ofail/$num\e[0m"
	echo -e "\e[45mTRANS PASSED: $tpass/$num\e[0m"
	echo -e "\e[45mTRANS FAILED: $tfail/$num\e[0m"
}

function delete { 
	#! testing delete
	echo -e "\e[0m-------------------------------\e[0m"
	echo -e "\e[104mTesting delete...\e[0m"
	
	cd 6_delete

	num="$(ls *.in -1 | wc -l)"

	opass=0
	ofail=0
	tpass=0
	tfail=0
	#./output 6_delete/01_loginlogout_std_session.in results/$timestamp/6_delete/01_loginlogout_std_session.testTrans
	echo "SUMMARY OF DELETE FOR $timestamp" >> ../results/$timestamp/6_delete.summary
	for ((i=1; i <= $num; i++))
	do

		echo -e "\e[95mRunning test $i\e[0m"
		num2="$(ls 0$i\_*.in)"
		#echo "${num2}"
		cd ../
		./quit.sh & ./output 6_delete/${num2} results/$timestamp/6_delete/$i.trans > results/$timestamp/6_delete/$i.out
		#sh -x ./quit.sh & ./output 6_delete/${num2} results/$timestamp/6_delete/$i.testTrans
		# script cannot progress because c++ program doesnt terminate... 
		
		cd 6_delete
		num3="$(ls 0$i\_*.out)"
		#echo -e "Checking output for test $i:"
		DIFF=$(diff ${num3} ../results/$timestamp/6_delete/$i.out) 

		if [ "$DIFF" != "" ] 
		then
			echo -e "\e[41mTEST ${num3} OUTPUT FAILED.\e[0m" 
			echo "TEST ${num3} OUTPUT FAILED." >> ../results/$timestamp/6_delete.summary
			ofail=$[ofail+1]
		else 
			echo -e "\e[42mTEST ${num3} OUTPUT PASSED.\e[0m" 
			echo "TEST ${num3} OUTPUT PASSED." >> ../results/$timestamp/6_delete.summary
			opass=$[opass+1]
		fi
		num4="$(ls 0$i\_*.trans)"
		DIFF2=$(diff ${num4} ../results/$timestamp/6_delete/$i.trans) 
		if [ "$DIFF2" != "" ] 
		then
			echo -e "\e[41mTEST ${num4} TRANSACTION FAILED.\e[0m" 
			echo "TEST ${num4} TRANSACTION FAILED." >> ../results/$timestamp/6_delete.summary
			tfail=$[tfail+1]
		else 
			echo -e "\e[42mTEST ${num4} TRANSACTION PASSED.\e[0m"
			echo "TEST ${num4} OUTPUT PASSED." >> ../results/$timestamp/6_delete.summary
			tpass=$[tpass+1]
		fi
		#./output 6_delete/01_loginlogout_std_session.in results/$timestamp/6_delete/01_loginlogout_std_session.testTrans
	done
	cd ../
	echo -e "\e[45mDelete test completed.\e[0m"
	echo -e "\e[45mOUTPUT PASSED: $opass/$num\e[0m"
	echo -e "\e[45mOUTPUT FAILED: $ofail/$num\e[0m"
	echo -e "\e[45mTRANS PASSED: $tpass/$num\e[0m"
	echo -e "\e[45mTRANS FAILED: $tfail/$num\e[0m"
}


function disable { 
	#! testing disable
	echo -e "\e[0m-------------------------------\e[0m"
	echo -e "\e[104mTesting disable...\e[0m"
	
	cd 7_disable

	num="$(ls *.in -1 | wc -l)"

	opass=0
	ofail=0
	tpass=0
	tfail=0
	#./output 7_disable/01_loginlogout_std_session.in results/$timestamp/7_disable/01_loginlogout_std_session.testTrans
	echo "SUMMARY OF DISABLE FOR $timestamp" >> ../results/$timestamp/7_disable.summary
	for ((i=1; i <= $num; i++))
	do

		echo -e "\e[95mRunning test $i\e[0m"
		num2="$(ls 0$i\_*.in)"
		#echo "${num2}"
		cd ../
		./quit.sh & ./output 7_disable/${num2} results/$timestamp/7_disable/$i.trans > results/$timestamp/7_disable/$i.out
		#sh -x ./quit.sh & ./output 7_disable/${num2} results/$timestamp/7_disable/$i.testTrans
		# script cannot progress because c++ program doesnt terminate... 
		
		cd 7_disable
		num3="$(ls 0$i\_*.out)"
		#echo -e "Checking output for test $i:"
		DIFF=$(diff ${num3} ../results/$timestamp/7_disable/$i.out) 

		if [ "$DIFF" != "" ] 
		then
			echo -e "\e[41mTEST ${num3} OUTPUT FAILED.\e[0m" 
			echo "TEST ${num3} OUTPUT FAILED." >> ../results/$timestamp/7_disable.summary
			ofail=$[ofail+1]
		else 
			echo -e "\e[42mTEST ${num3} OUTPUT PASSED.\e[0m" 
			echo "TEST ${num3} OUTPUT PASSED." >> ../results/$timestamp/7_disable.summary
			opass=$[opass+1]
		fi
		num4="$(ls 0$i\_*.trans)"
		DIFF2=$(diff ${num4} ../results/$timestamp/7_disable/$i.trans) 
		if [ "$DIFF2" != "" ] 
		then
			echo -e "\e[41mTEST ${num4} TRANSACTION FAILED.\e[0m" 
			echo "TEST ${num4} TRANSACTION FAILED." >> ../results/$timestamp/7_disable.summary
			tfail=$[tfail+1]
		else 
			echo -e "\e[42mTEST ${num4} TRANSACTION PASSED.\e[0m"
			echo "TEST ${num4} OUTPUT PASSED." >> ../results/$timestamp/7_disable.summary
			tpass=$[tpass+1]
		fi
		#./output 7_disable/01_loginlogout_std_session.in results/$timestamp/7_disable/01_loginlogout_std_session.testTrans
	done

	cd ../
	echo -e "\e[45mDisable test completed.\e[0m"
	echo -e "\e[45mOUTPUT PASSED: $opass/$num\e[0m"
	echo -e "\e[45mOUTPUT FAILED: $ofail/$num\e[0m"
	echo -e "\e[45mTRANS PASSED: $tpass/$num\e[0m"
	echo -e "\e[45mTRANS FAILED: $tfail/$num\e[0m"
}

function enable1 { 
	#! testing enable
	echo -e "\e[0m-------------------------------\e[0m"
	echo -e "\e[104mTesting enable...\e[0m"
	
	cd 8_enable

	num="$(ls *.in -1 | wc -l)"

	opass=0
	ofail=0
	tpass=0
	tfail=0
	#./output 8_enable/01_loginlogout_std_session.in results/$timestamp/8_enable/01_loginlogout_std_session.testTrans
	echo "SUMMARY OF ENABLE FOR $timestamp" >> ../results/$timestamp/8_enable.summary
	for ((i=1; i <= $num; i++))
	do

		echo -e "\e[95mRunning test $i\e[0m"
		num2="$(ls 0$i\_*.in)"
		#echo "${num2}"
		cd ../
		./quit.sh & ./output 8_enable/${num2} results/$timestamp/8_enable/$i.trans > results/$timestamp/8_enable/$i.out
		#sh -x ./quit.sh & ./output 8_enable/${num2} results/$timestamp/8_enable/$i.testTrans
		# script cannot progress because c++ program doesnt terminate... 
		
		cd 8_enable
		num3="$(ls 0$i\_*.out)"
		#echo -e "Checking output for test $i:"
		DIFF=$(diff ${num3} ../results/$timestamp/8_enable/$i.out) 

		if [ "$DIFF" != "" ] 
		then
			echo -e "\e[41mTEST ${num3} OUTPUT FAILED.\e[0m" 
			echo "TEST ${num3} OUTPUT FAILED." >> ../results/$timestamp/8_enable.summary
			ofail=$[ofail+1]
		else 
			echo -e "\e[42mTEST ${num3} OUTPUT PASSED.\e[0m" 
			echo "TEST ${num3} OUTPUT PASSED." >> ../results/$timestamp/8_enable.summary
			opass=$[opass+1]
		fi
		num4="$(ls 0$i\_*.trans)"
		DIFF2=$(diff ${num4} ../results/$timestamp/8_enable/$i.trans) 
		if [ "$DIFF2" != "" ] 
		then
			echo -e "\e[41mTEST ${num4} TRANSACTION FAILED.\e[0m" 
			echo "TEST ${num4} TRANSACTION FAILED." >> ../results/$timestamp/8_enable.summary
			tfail=$[tfail+1]
		else 
			echo -e "\e[42mTEST ${num4} TRANSACTION PASSED.\e[0m"
			echo "TEST ${num4} OUTPUT PASSED." >> ../results/$timestamp/8_enable.summary
			tpass=$[tpass+1]
		fi
		#./output 8_enable/01_loginlogout_std_session.in results/$timestamp/8_enable/01_loginlogout_std_session.testTrans
	done
	cd ../
	echo -e "\e[45mEnable test completed.\e[0m"
	echo -e "\e[45mOUTPUT PASSED: $opass/$num\e[0m"
	echo -e "\e[45mOUTPUT FAILED: $ofail/$num\e[0m"
	echo -e "\e[45mTRANS PASSED: $tpass/$num\e[0m"
	echo -e "\e[45mTRANS FAILED: $tfail/$num\e[0m"
}

function changeplan { 
	#! testing changeplan
	echo -e "\e[0m-------------------------------\e[0m"
	echo -e "\e[104mTesting changeplan...\e[0m"
	cd 9_changeplan

	num="$(ls *.in -1 | wc -l)"

	opass=0
	ofail=0
	tpass=0
	tfail=0
	#./output 9_changeplan/01_loginlogout_std_session.in results/$timestamp/9_changeplan/01_loginlogout_std_session.testTrans
	echo "SUMMARY OF CHANGEPLAN FOR $timestamp" >> ../results/$timestamp/9_changeplan.summary
	for ((i=1; i <= $num; i++))
	do

		echo -e "\e[95mRunning test $i\e[0m"
		num2="$(ls 0$i\_*.in)"
		#echo "${num2}"
		cd ../
		./quit.sh & ./output 9_changeplan/${num2} results/$timestamp/9_changeplan/$i.trans > results/$timestamp/9_changeplan/$i.out
		#sh -x ./quit.sh & ./output 9_changeplan/${num2} results/$timestamp/9_changeplan/$i.testTrans
		# script cannot progress because c++ program doesnt terminate... 
		
		cd 9_changeplan
		num3="$(ls 0$i\_*.out)"
		#echo -e "Checking output for test $i:"
		DIFF=$(diff ${num3} ../results/$timestamp/9_changeplan/$i.out) 

		if [ "$DIFF" != "" ] 
		then
			echo -e "\e[41mTEST ${num3} OUTPUT FAILED.\e[0m" 
			echo "TEST ${num3} OUTPUT FAILED." >> ../results/$timestamp/9_changeplan.summary
			ofail=$[ofail+1]
		else 
			echo -e "\e[42mTEST ${num3} OUTPUT PASSED.\e[0m" 
			echo "TEST ${num3} OUTPUT PASSED." >> ../results/$timestamp/9_changeplan.summary
			opass=$[opass+1]
		fi
		num4="$(ls 0$i\_*.trans)"
		DIFF2=$(diff ${num4} ../results/$timestamp/9_changeplan/$i.trans) 
		if [ "$DIFF2" != "" ] 
		then
			echo -e "\e[41mTEST ${num4} TRANSACTION FAILED.\e[0m" 
			echo "TEST ${num4} TRANSACTION FAILED." >> ../results/$timestamp/9_changeplan.summary
			tfail=$[tfail+1]
		else 
			echo -e "\e[42mTEST ${num4} TRANSACTION PASSED.\e[0m"
			echo "TEST ${num4} OUTPUT PASSED." >> ../results/$timestamp/9_changeplan.summary
			tpass=$[tpass+1]
		fi
		#./output 9_changeplan/01_loginlogout_std_session.in results/$timestamp/9_changeplan/01_loginlogout_std_session.testTrans
	done


	cd ../
	echo -e "\e[45mChangeplan test completed.\e[0m"
	echo -e "\e[45mOUTPUT PASSED: $opass/$num\e[0m"
	echo -e "\e[45mOUTPUT FAILED: $ofail/$num\e[0m"
	echo -e "\e[45mTRANS PASSED: $tpass/$num\e[0m"
	echo -e "\e[45mTRANS FAILED: $tfail/$num\e[0m"
}

function all { 
	echo "Running all tests..."
	loginlogout
	sleep 1
	withdrawal
	sleep 1
	transfer
	sleep 1
	paybill
	sleep 1
	deposit
	sleep 1
	create
	sleep 1
	delete
	sleep 1
	disable
	sleep 1
	enable1
	sleep 1
	changeplan
	echo -e "\e[45mAll tests completed.\e[0m"
}

#! welcome message
echo -e "\e[36m--------------------------------"
echo -e "\e[36m| Welcome to front - end tests |"
echo -e "\e[36m--------------------------------"

timestamp=$( date +%Y-%m-%d_%H-%M-%S )

mkdir results
cd results

rm -rf *

mkdir $timestamp
cd $timestamp
echo $timestamp

mkdir "0_loginlogout"
mkdir "1_withdrawal"
mkdir "2_transfer"
mkdir "3_paybill"
mkdir "4_deposit"
mkdir "5_create"
mkdir "6_delete"
mkdir "7_disable"
mkdir "8_enable"
mkdir "9_changeplan"

cd ../../

echo "Which tests would you like to run?"

while true; do
	echo -e "\e[36m0) 0_login/logout    3) 3_paybill	 6) 6_delete	    9) 9_changeplan
1) 1_withdrawal	     4) 4_deposit	 7) 7_disable	    
2) 2_transfer	     5) 5_create	 8) 8_enable"
	read input

#!select input in "1_login/logout" "2_withdrawal" "3_transfer" "4_paybill" "5_deposit" "6_create" "7_delete" "8_disable" "9_enable" "10_changeplan" "0_all"; do
    case $input in 
        [0] ) loginlogout ;;
        [1] ) withdrawal ;; 
		[2] ) transfer ;; 
		[3] ) paybill ;; 
		[4] ) deposit ;; 
		[5] ) create ;; 
		[6] ) delete ;; 
		[7] ) disable ;; 
		[8] ) enable1 ;; 
		[9] ) changeplan ;; 
		*) echo -e "\e[31m-------------------------------\nInvalid option, running all tests\e[0m"; all ; exit ;;
    esac
done