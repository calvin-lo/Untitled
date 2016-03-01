#!/bin/bash

function loginlogout { 
	#! testing login and logout
	echo -e "\e[44mTesting login and logout...\e[0m"
	./output 0_loginlogout/01_loginlogout_std_session.in 
	
	#foreach i (*)
	#	echo “running test $i”
	#	banksys currentaccounts.txt  ../outputs/$i.atf \< $i > ../outputs/$i.out
	#end

	echo -e "\e[45mLogin and logout test completed.\e[0m"
}

function withdrawal { 
	#! testing withdrawal
	
	echo -e "\e[0m-------------------------------\e[0m"
	echo -e "\e[44mTesting withdrawal...\e[0m"
	
	
	echo -e "\e[45mWithdrawal test completed.\e[0m"
}

function transfer { 
	#! testing transfer

	echo -e "\e[0m-------------------------------\e[0m"
	echo -e "\e[44mTesting transfer...\e[0m"


	echo -e "\e[45mTransfer test completed.\e[0m"
}


function paybill { 
	#! testing paybill
	echo -e "\e[0m-------------------------------\e[0m"
	echo -e "\e[44mTesting paybill...\e[0m"
	
	echo -e "\e[45mPaybill test completed.\e[0m"
}

function deposit { 
	#! testing deposit
	echo -e "\e[0m-------------------------------\e[0m"
	echo -e "\e[44mTesting deposit...\e[0m"
	
	echo -e "\e[45mDeposit test completed.\e[0m"
}


function create { 
	#! testing create
	echo -e "\e[0m-------------------------------\e[0m"
	echo -e "\e[44mTesting create...\e[0m"
	
	echo -e "\e[45mCreate test completed.\e[0m"
}

function delete { 
	#! testing delete
	echo -e "\e[0m-------------------------------\e[0m"
	echo -e "\e[44mTesting delete...\e[0m"
	
	echo -e "\e[45mDelete test completed.\e[0m"
}


function disable { 
	#! testing disable
	echo -e "\e[0m-------------------------------\e[0m"
	echo -e "\e[44mTesting disable...\e[0m"
	
	echo -e "\e[45mDisable test completed.\e[0m"
}

function enable1 { 
	#! testing enable
	echo -e "\e[0m-------------------------------\e[0m"
	echo -e "\e[44mTesting enable...\e[0m"
	
	echo -e "\e[45mEnable test completed.\e[0m"
}

function changeplan { 
	#! testing changeplan
	echo -e "\e[0m-------------------------------\e[0m"
	echo -e "\e[44mTesting changeplan...\e[0m"
	
	echo -e "\e[45mChangeplan test completed.\e[0m"
}

function all { 
	echo "Running all tests..."
	loginlogout
	withdrawal
	paybill
	deposit
	create
	delete
	disable
	enable1
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