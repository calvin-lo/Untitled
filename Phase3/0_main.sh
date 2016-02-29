#!/bin/bash

function loginlogout { 
	#! testing login and logout
	echo -e "\e[44mTesting login and logout...\e[0m"
	cd 1_loginlogout
	#! mkdir output
	cd ../
}

function withdrawal { 
	#! testing withdrawal
	echo -e "\e[0m-------------------------------\e[0m"
	echo -e "\e[44mTesting withdrawal...\e[0m"
	cd 2_withdrawal
	#! mkdir output
	cd ../
}

function transfer { 
	#! testing transfer
	echo -e "\e[0m-------------------------------\e[0m"
	echo -e "\e[44mTesting transfer...\e[0m"
	cd 3_transfer
	#! mkdir output
	cd ../
}


function paybill { 
	#! testing paybill
	echo -e "\e[0m-------------------------------\e[0m"
	echo -e "\e[44mTesting paybill...\e[0m"
	cd 4_paybill
	#! mkdir output
	cd ../
}

function deposit { 
	#! testing deposit
	echo -e "\e[0m-------------------------------\e[0m"
	echo -e "\e[44mTesting deposit...\e[0m"
	cd 5_deposit
	#! mkdir output
	cd ../
}


function create { 
	#! testing create
	echo -e "\e[0m-------------------------------\e[0m"
	echo -e "\e[44mTesting create...\e[0m"
	cd 6_create
	#! mkdir output
	cd ../
}

function delete { 
	#! testing delete
	echo -e "\e[0m-------------------------------\e[0m"
	echo -e "\e[44mTesting delete...\e[0m"
	cd 7_delete
	#! mkdir output
	cd ../
}


function disable { 
	#! testing disable
	echo -e "\e[0m-------------------------------\e[0m"
	echo -e "\e[44mTesting disable...\e[0m"
	cd 8_disable
	#! mkdir output
	cd ../
}

function enable1 { 
	#! testing enable
	echo -e "\e[0m-------------------------------\e[0m"
	echo -e "\e[44mTesting enable...\e[0m"
	cd 9_enable
	#! mkdir output
	cd ../
}

function changeplan { 
	#! testing changeplan
	echo -e "\e[0m-------------------------------\e[0m"
	echo -e "\e[44mTesting changeplan...\e[0m"
	cd ../10_changeplan
	#! mkdir output
	cd ../
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
}
#! welcome message
echo -e "\e[36m--------------------------------"
echo -e "\e[36m| Welcome to front - end tests |"
echo -e "\e[36m--------------------------------"

echo "Which tests would you like to run?"

while true; do
	echo -e "\e[36m0) 1_login/logout    5) 4_paybill	 8) 7_delete	    9) 10_changeplan
1) 2_withdrawal	     3) 5_deposit	 6) 8_disable	    
2) 3_transfer	     4) 6_create	 7) 9_enable"
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
		*) echo -e "\e[31m-------------------------------\nInvalid option, running all tests\e[0m" all ;;
    esac
done
