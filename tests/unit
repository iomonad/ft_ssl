#!/bin/bash

# Depedencies: (all external commands)
#  - bash
#  - dd
#  - od
#  - tr
#  - diff
#  - grep
#  - cat
#  - printf
#  - echo
#  - head
#  - rm
#  - openssl
#  - shasum
#  - mktemp
#  - tput

# const strings

MD5_META="openssl md5,./ft_ssl md5"
MD4_META="openssl md4,./ft_ssl md4"
SHA256_META="openssl sha -sha256,./ft_ssl sha256"
SHA1_META="openssl sha -sha1,./ft_ssl sha1"
SHA224_META="openssl sha -sha224,./ft_ssl sha224"
SHA384_META="openssl sha -sha384,./ft_ssl sha384"
SHA512_META="openssl sha -sha512,./ft_ssl sha512"
SHA512224_META="shasum -a 512224,./ft_ssl sha512_224"
SHA512256_META="shasum -a 512256,./ft_ssl sha512_256"

# You may have to change the option of base64 for decrypt (differs in versions)
BASE64="base64,base64 -d,./ft_ssl base64,./ft_ssl base64 -d,1"
BASE64_URL="base64 | tr '+/' '-_', tr -- '-_' '+/' | base64 -d,./ft_ssl base64_url,./ft_ssl base64_url -d,1"

# FIXME you can change this if you don't handle such features

HASH_META="${MD5_META};${SHA256_META};${SHA224_META};${SHA384_META};${SHA512_META};"
MODES_META="des-ecb;des-cbc;des-cfb;des-ofb;"
BASE64_META="${BASE64};${BASE64_URL};"

# FIXME you can change the default values of nb_keys and nb_ivs

NB_KEYS="3"
NB_IVS="1"

# FIXME you can change the default value of the number of random inputs

NB_RANDOM_INPUT="100"

################################## CORE ########################################

_RED=$(tput setaf 1 2> /dev/null || echo "")
_GREEN=$(tput setaf 2 2> /dev/null || echo "")
# _YELLOW=$(tput setaf 3 2> /dev/null || echo "")
# _BLUE=$(tput setaf 4 2> /dev/null || echo "")
# _PURPLE=$(tput setaf 5 2> /dev/null || echo "")
_CYAN=$(tput setaf 6 2> /dev/null || echo "")
# _WHITE=$(tput setaf 7 2> /dev/null || echo "")
_END=$(tput sgr0 2> /dev/null || echo "")

RANDOM_EIGHT_HEX_NUM="dd if=/dev/random bs=8 count=1 2>/dev/null | od -An -tx1 | tr -d ' \\n\\t'"

TMP_SCORE=$(mktemp)
TMP_FILE=$(mktemp)
DUMP_LEAKS_FILE="dump_leaks.txt"

KEYS=""
IVS=""

for (( i = 0; i < NB_KEYS; i++ )); do
	KEY=$(eval "${RANDOM_EIGHT_HEX_NUM}")
	KEYS="${KEYS}${KEY};"
done

for (( i = 0; i < NB_IVS; i++ )); do
	IV=$(eval "${RANDOM_EIGHT_HEX_NUM}")
	IVS="${IVS}${IV};"
done

build_commands()
{
	rm -f tmp.txt
	echo "${BASE64_META}" | while read -r -d';' BASE; do
		echo "${BASE};" >> tmp.txt
	done
	echo "${MODES_META}" | while read -r -d';' MODE; do
		echo "${KEYS}" | while read -r -d';' KEY; do
			if [ "${MODE}" = "des-ecb" ]; then
				echo "openssl ${MODE} -K ${KEY},openssl ${MODE} -d -K ${KEY},./ft_ssl ${MODE} -k ${KEY},./ft_ssl ${MODE} -d -k ${KEY},0;" >> tmp.txt
			else
				echo "${IVS}" | while read -r -d';' IV; do
					echo "openssl ${MODE} -K ${KEY} -iv ${IV},openssl ${MODE} -d -K ${KEY} -iv ${IV},./ft_ssl ${MODE} -k ${KEY} -v ${IV},./ft_ssl ${MODE} -d -k ${KEY} -v ${IV},0;" >> tmp.txt
				done
			fi
		done
	done
	tr -d '\n' < tmp.txt
	rm -f tmp.txt
}

ENCRYPT_META="$(build_commands)"

# Fixed entries
# those entries test all possible scenarios for padding in all algorithms

DATA=$(cat << EOL
.Je suis un poulet sur patte.Et accesoirement une patate.pickle rick.Do not pity with the dead, Harry..Pity the living.And above all,.pity those that aren't following baerista on spotify..be sure to handle edge cases carefully.some of this will not make sense at first.GL HF let's go.one more thing.just to be extra clear.just an extra test...Lorem ipsum dolor sit amet, consectetur adipiscing elit. Proin arcu magna, tincidunt quis risus nec, pretium egestas mi. Praesent id sagittis nisl. Mauris pretium lectus orci, sit amet pulvinar dolor maximus sit amet. Duis nulla lorem, vulputate vitae tempus id, eleifend nec nulla. Proin quis urna sed nibh porttitor convallis sed vitae tortor. Ut tincidunt, dui non finibus mattis, ipsum nunc lobortis augue, vel placerat ligula justo id nunc. Aliquam porta felis vel velit accumsan, et laoreet magna fermentum. Nam lectus nisl, pretium imperdiet orci vitae, laoreet vulputate arcu. Proin efficitur consectetur enim, nec sollicitudin nunc. Proin finibus mollis velit ac scelerisque. Integer varius tempor lacus, ut varius urna rutrum quis. Aenean consectetur lacinia ante. Integer eu tempor sapien. Ut magna nulla, commodo et lacus non, tempor commodo dui...Etiam consequat viverra nisi nec varius. Ut elementum nibh facilisis diam consequat scelerisque. Morbi sit amet dui tempor nisi maximus eleifend. Proin eget mattis enim. Suspendisse potenti. Sed sem mi, vehicula nec aliquet et, tristique vel est. Integer ullamcorper eleifend luctus. Suspendisse sagittis nunc eget consequat volutpat. Nam dapibus vestibulum lectus nec scelerisque. Nulla id ligula luctus, rhoncus metus in, laoreet ex. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas...Mauris vel diam malesuada, posuere odio at, pretium augue. Duis in lorem turpis. Suspendisse dapibus eu leo eu lacinia. Proin egestas ipsum et quam hendrerit sodales. Sed eu tortor eu nulla efficitur sodales. Pellentesque hendrerit felis eget magna aliquet, in cursus ipsum gravida. Donec in vulputate nisi, sed convallis magna. Cras vel orci lacinia, elementum nunc vitae, rutrum ex...Fusce feugiat, quam vitae placerat viverra, libero odio tempor neque, in iaculis dui ante vel sapien. Aenean in est a est volutpat convallis. Ut in metus et nisl dapibus cursus. Ut eu molestie ligula. Quisque diam nulla, condimentum ut pretium eget, varius eu nisl. Proin pellentesque facilisis ex id rutrum. Donec quis diam tincidunt, fermentum ligula ut, aliquet elit. Suspendisse felis ligula, viverra vitae semper vitae, malesuada eu ligula. Fusce faucibus ante enim, id aliquet nulla faucibus a...In eu velit id lectus interdum consequat. Vivamus a enim mollis, imperdiet orci nec, porttitor velit. Sed imperdiet diam eget mauris varius vehicula. Pellentesque rhoncus ex feugiat libero egestas, ut congue risus varius. Interdum et malesuada fames ac ante ipsum primis in faucibus. Nam quam leo, aliquam vel porttitor sed, sollicitudin quis elit. Aenean aliquet eget libero quis vehicula. Suspendisse ut lobortis libero, vel bibendum justo. Pellentesque lacinia condimentum purus et sagittis. Ut ultrices, enim sed aliquet ornare, leo libero auctor nulla, quis sollicitudin sem urna et mi. Vestibulum quis tincidunt purus, at ultrices elit. Cras diam metus, sollicitudin sed mauris vitae, tempor ornare erat. Phasellus sed urna tellus._________________.__________________________________.___________________________________________________.____________________________________________________________________._____________________________________________________________________________________.______________________________________________________________________________________________________._______________________________________________________________________________________________________________________.________________________________________________________________________________________________________________________________________._________________________________________________________________________________________________________________________________________________________.__________________________________________________________________________________________________________________________________________________________________________.___________________________________________________________________________________________________________________________________________________________________________________________.____________________________________________________________________________________________________________________________________________________________________________________________________________._____________________________________________________________________________________________________________________________________________________________________________________________________________________________.______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________._______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________.________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________._________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________.__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________.___________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________.____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________._____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________.______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________._______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________.________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________._________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________.__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________.___________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________.____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________._____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________.込作金連携南政育平挙活世激即逆転。東断化情教野画摂景戒保在端身。手回実化燃話政橋売録史国年由力長准必転申。摘提況索属応局際伺断任写行普波踏。氏史跡戦再条平本企前革板様熊。過去女参主戸平実無年洗正旅真周強極。出戦覧手車足連内応縄都図保住。強権定夜高尿陽参高合宝提駐高選単北正。新手問思後力暮挑録博酒帯止物。.
EOL
)

# some utils functions

compt_OK()
{
	N=$(cat "${TMP_SCORE}")
	if [ -z "${N}" ]; then
		printf "OK %s1%s" "${_GREEN}" "${_END}"
		echo "1" > "${TMP_SCORE}"
	else
		N=$((N + 1))
		printf "\\rOK %s%d%s" "${_GREEN}" "${N}" "${_END}"
		echo "${N}" > "${TMP_SCORE}"
	fi
}

compt_reset()
{
	echo "" > "${TMP_SCORE}"
	printf "\\n"
}

header()
{
	for (( i = 0; i < 80 / 5; i++ )); do
		printf "#####"
	done
	printf "\\n#####"
	M=${#1}
	N=$((35 - (M / 2)))
	O=$((70 - N - M))
	for (( i = 0; i < N; i++ )); do
		printf " "
	done
	printf "%s" "${1}"
	for (( i = 0; i < O; i++ )); do
		printf " "
	done
	printf "#####\\n"
	for (( i = 0; i < 80 / 5; i++ )); do
		printf "#####"
	done
	printf "\\n\\n"
}

# ================ Abstract check hash function =====================
# takes 3 arguments
# the 1st is a file which contains the content tested
# the 2nd is the real command executed
# the 3rd is the tested command (e.g.: ./ft_ssl base64)
# the _check_hash will execute and compare outputs

_check_hash()
{
	INPUT="$1"
	REAL_CMD="$2"
	MINE_CMD="$3"

	OR=$(eval "cat ${INPUT} | ${REAL_CMD} | sed 's/(stdin)//' | tr -d '= -'")
	OM=$(eval "cat ${INPUT} | ${MINE_CMD}")
	if ! [ "${OR}" = "${OM}" ]; then
		RET=1
		compt_reset
		printf "Failed on : %s\\n" "${INPUT}"
		echo "${OR}"
		echo "${OM}"
		exit
	else
		compt_OK
	fi
}

# ================= Abstract check des function =======================
# takes 5 arguments
# the 1st is a file which contains the content tested
# the 2nd is the real command executed for encrypt
# the 3rd is the tested command for encrypt (e.g.: ./ft_ssl des-ecb -k 1122)
# the 4th is the real command executed for decrypt
# the 5th is the tested command for decrypt (e.g.: ./ft_ssl des-ecb -d -k 1122)
# the 6th is a boolean that delete newline and spaces in both outputs
#               it is usefull for base64
# the _check_hash will execute and compare outputs

_check_des()
{
	INPUT="$1"
	REAL_ENC="$2"
	REAL_DEC="$3"
	MINE_ENC="$4"
	MINE_DEC="$5"
	DELETE_SP="$6"
	ENC_OUT_REAL="enc_real.out"
	ENC_OUT_MINE="enc_mine.out"
	DEC_OUT_REAL="dec_real.out"
	DEC_OUT_MINE="dec_mine.out"

	eval "cat ${INPUT} | ${REAL_ENC}" > ${ENC_OUT_REAL}
	eval "cat ${INPUT} | ${MINE_ENC}" > ${ENC_OUT_MINE}
	if [ "${DELETE_SP}" = "1" ]; then
		tmp=$(mktemp)
		tr -d '\n ' < "${ENC_OUT_REAL}" > "${tmp}"
		mv "${tmp}" "${ENC_OUT_REAL}"
		tr -d '\n ' < "${ENC_OUT_MINE}" > "${tmp}"
		mv "${tmp}" "${ENC_OUT_MINE}"
		rm -f "${tmp}"
	fi
	eval "cat ${ENC_OUT_REAL} | ${REAL_DEC}" > ${DEC_OUT_REAL}
	eval "cat ${ENC_OUT_MINE} | ${MINE_DEC}" > ${DEC_OUT_MINE}
	if diff ${ENC_OUT_REAL} ${ENC_OUT_MINE} > /dev/null 2>&1 && diff ${DEC_OUT_REAL} ${DEC_OUT_MINE} > /dev/null 2>&1; then
		compt_OK
	else
		diff ${ENC_OUT_REAL} ${ENC_OUT_MINE}
		diff ${DEC_OUT_REAL} ${DEC_OUT_MINE}
		compt_reset
		printf "Failed on : %s\\n" "${INPUT}"
		exit 1
	fi
	rm -f ${ENC_OUT_REAL} ${ENC_OUT_MINE} ${DEC_OUT_REAL} ${DEC_OUT_MINE}
}

# The following use abstract functions with fixed data and random data

# checks_hash checks hash with fixed data
checks_hash()
{
	header "Test script - Hash functions"
	echo "${HASH_META}" | while IFS=',' read -r -d';' A B; do
		printf "============ %s ===========\\n" "${B}"
		echo "${DATA}" | while read -r -d'.' STR; do
			echo "${STR}" > "${TMP_FILE}"
			_check_hash "${TMP_FILE}" "${A}" "${B}"
		done
		compt_reset
	done
}

# checks_hash checks hash with random data
checks_random_hash()
{
	header "Test script - Hash functions (random input)"
	echo "${HASH_META}" | while IFS=',' read -r -d';' A B; do
		printf "============ %s ===========\\n" "${B}"
		for (( i = 0; i < NB_RANDOM_INPUT; i++ )); do
			head -c ${RANDOM} < /dev/urandom > "${TMP_FILE}"
			_check_hash "${TMP_FILE}" "${A}" "${B}"
		done
		compt_reset
	done
}

# checks_des checks hash with fixed data
checks_des()
{
	header "Test script - Des modes and base64"
	echo "${ENCRYPT_META}" | while IFS=',' read -r -d';' A B C D E; do
		printf "============ %s ===========\\n" "${C}"
		echo "${DATA}" | while read -r -d'.' STR; do
			echo "${STR}" > "${TMP_FILE}"
			_check_des "${TMP_FILE}" "${A}" "${B}" "${C}" "${D}" "${E}"
		done
		compt_reset
	done
}

# checks_des checks hash with random data
checks_random_des()
{
	header "Test script - Des modes and base64 (random input)"
	echo "${ENCRYPT_META}" | while IFS=',' read -r -d';' A B C D E; do
		printf "============ %s ===========\\n" "${C}"
		for (( i = 0; i < NB_RANDOM_INPUT; i++ )); do
			head -c ${RANDOM} < /dev/urandom > "${TMP_FILE}"
			_check_des "${TMP_FILE}" "${A}" "${B}" "${C}" "${D}" "${E}"
		done
		compt_reset
	done
}

# utils functions that checks leaks
# there is a leak if definitely lost is present AND that number of bytes lost is not zero

_check_leak()
{
	BEG_CMD="if !"
	END_CMD="2>&1 | tee -a ${DUMP_LEAKS_FILE} | grep 'definitely lost' | grep -v ' 0 bytes' ; then printf '${_GREEN}OK${_END}'; else printf '${_RED}KO${_END}'; fi"

	eval "${BEG_CMD} $* ${END_CMD}"
	printf " : \"%s\"\\n" "$*"
}

# test bench of COMMANDES
# FIXME you can change this if you don't handle such features

checks_leaks()
{
	VG="valgrind --leak-check=full"
	RD="cat /dev/urandom | head -c 512"
	CMD="${VG} ./ft_ssl"

	header "Test script - check leaks"
	rm -f ${DUMP_LEAKS_FILE}
	_check_leak "${CMD}"
	echo "${HASH_META}" | while IFS=',' read -r -d';' REAL_CMD MINE_CMD; do
		_check_leak "${RD} | ${VG} ${MINE_CMD}"
		_check_leak "${RD} | ${VG} ${MINE_CMD} -h"
		_check_leak "${RD} | ${VG} ${MINE_CMD} -r"
		_check_leak "${RD} | ${VG} ${MINE_CMD} -rq"
		_check_leak "${RD} | ${VG} ${MINE_CMD} -p"
		_check_leak "${RD} | ${VG} ${MINE_CMD} -pq"
		_check_leak "${RD} | ${VG} ${MINE_CMD} -pq -s 'oui'"
		_check_leak "${RD} | ${VG} ${MINE_CMD} -pqr -s 'oui'"
		_check_leak "${RD} | ${VG} ${MINE_CMD} -pq -s 'oui' -s 'non'"
		_check_leak "${RD} | ${VG} ${MINE_CMD} -pqr -s 'oui' -s 'non'"
	done
	for ba in base64 base64_url; do
		_check_leak "${RD} | ${CMD} ${ba}"
		_check_leak "${RD} | ${CMD} ${ba} -e"
		_check_leak "${RD} | ${CMD} ${ba} -e -o tmp"
		_check_leak "${CMD} ${ba} -i ./ft_ssl -o tmp"
		_check_leak "${CMD} ${ba} -i ./ft_ssl -e -e -e -o tmp"
		_check_leak "${CMD} ${ba} -i ./ft_ssl -eee -o tmp"
		_check_leak "${CMD} ${ba} -i tmp -d"
		_check_leak "${CMD} ${ba} -i ./ft_ssl -d"
	done
	eval "${RD} > tmp2"
	echo "${MODES_META}" | while read -r -d';' MODE; do
		echo "${KEYS}" | while read -r -d';' KEY; do
			IV=$(echo -n "${KEY}" | tr '0123456789ABCDEF' '49F378BD6A10C25E')
			_check_leak "${RD} | ${CMD} ${MODE} -k ${KEY} -v ${IV}"
			_check_leak "${RD} | ${CMD} ${MODE} -k ${KEY} -v ${IV} -e"
			_check_leak "${RD} | ${CMD} ${MODE} -k ${KEY} -v ${IV} -e -o tmp"
			_check_leak "${CMD} ${MODE} -k ${KEY} -v ${IV} -i tmp2 -o tmp"
			_check_leak "${CMD} ${MODE} -k ${KEY} -v ${IV} -i tmp2 -e -e -e -o tmp"
			_check_leak "${CMD} ${MODE} -k ${KEY} -v ${IV} -i tmp2 -eee -o tmp"
			_check_leak "${CMD} ${MODE} -k ${KEY} -v ${IV} -i tmp -d"
			_check_leak "${CMD} ${MODE} -k ${KEY} -v ${IV} -i tmp2 -d"
		done
	done
	rm tmp tmp2
}

#################################### MAIN ######################################

usage()
{
	printf "Usage: bash tests.sh [loop] cmd\\n"
	printf "\\n"
	printf "This script tests if your version is a good implementation of hashing and encrypting algorithms.\\n"
	printf "All outputs are compared with openssl outputs (and shasum for sha family).\\n"
	printf "\\n"
	printf "You may have to modify this script by changing the header of the script.\\n"
	printf "Make sure to respect the format.\\n"
	printf "\\n"
	printf "loop is an optional command that executes the given command in an infinite loop.\\n"
	printf "The only way to stop the program is to kill it.\\n"
	printf "If you're not running any other program in bash, you can simply 'killall bash'.\\n"
	printf "\\n"
	printf "cmd is one of the following :\\n"
	printf "\\t- hash : check hash of fixed data\\n"
	printf "\\t- random_hash : check hash of random data\\n"
	printf "\\t- des : check des of fixed data (includes base64)\\n"
	printf "\\t- random_des : check des of random data (includes base64)\\n"
	printf "\\t- random : check hash and des of random data\\n"
	printf "\\t- leaks : checks leaks of several commands\\n"
	printf "\\t- all : all of above\\n"
	printf "\\t- usage|help : print this message\\n"
}

# stop if ft_ssl is not present in the current directory

if [ ! -f ./ft_ssl ]; then
	printf "Run make all before...\\n"
	exit 1
fi

RET=0
LOOP=0

if [ $# = 2 ]; then
	if [ "$1" = "loop" ]; then
		LOOP=1
		printf "the program is in loop mode, kill it if you want to stop it\\n"
	else
		printf "the argument %s is ignored, must be loop\\n" "$1"
	fi
	shift
fi

if ! [ $# = 1 ]; then
	usage
	RET=1
else
	case $1 in
		hash )
			checks_hash
			;;
		random_hash )
			checks_random_hash
			;;
		des )
			checks_des
			;;
		random_des )
			checks_random_des
			;;
		random )
			checks_random_hash
			checks_random_des
			;;
		leaks )
			checks_leaks
			;;
		all )
			checks_hash
			checks_random_hash
			checks_des
			checks_random_des
			checks_leaks
			;;
		usage|help )
			usage
			;;
		* )
			usage
			RET=1
			;;
	esac
fi

if ! [ $RET = "0" ]; then
	rm -rf "${TMP_SCORE}"
	rm -rf "${TMP_FILE}"
fi

if [ $LOOP = "1" ] && [ $RET = "0" ]; then
	printf "%sLOOPING%s\\n" "${_CYAN}" "${_END}"
	bash "$0" "loop" "$1"
fi

exit ${RET}
