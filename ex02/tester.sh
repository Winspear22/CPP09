#!/bin/bash

# Définir les codes de couleurs et de formatage
bold="\033[1m"
blue="\033[1;34m"
green="\033[1;32m"
yellow="\033[1;33m"
white="\033[1;37m"
normal="\033[0m"

echo "${blue}Test effectué :${white} $1"
echo "${green}Résultat escompté :${white} $2"
echo "${yellow}Votre résultat :${normal}"
./PmergeMe $1
echo

# Fonction pour effectuer un test
test_case() {
    input=$1
    expected_output=$2

    echo "${blue}${bold}Test effectué :${normal} ${white}${bold}${input}${normal}"
    echo "${green}${bold}Résultat escompté :${normal} ${white}${bold}${expected_output}${normal}"

    # Exécuter le programme PmergeMe avec les arguments donnés et stocker la sortie et le code de retour
    output=$(./PmergeMe $input 2>&1)
    result=$?

    # Afficher le résultat réel
    echo "${yellow}${bold}Votre résultat :${normal} ${white}${bold}${output}${normal}"
    echo ""

    return $result
}

# Tests
test_case "-1 5 2 13" "Error"
test_case "3 2 1 \"\"" "Error"
test_case "3 2 1 \"  \"" "Error"
test_case "3 2 1 \"\t\"" "Error"
test_case "3 2 1 \"\n\"" "Error"
test_case "2147483648" "Error"

random_input=$(shuf -i 1-100000 -n 3000 | tr "\n" " ")
test_case "1 ${random_input} -1" "Error"

random_input_with_spaces=" 1   7 4  2 9  5  8   3  6  "
test_case "${random_input_with_spaces}a" "Error"

random_input_with_tabs="1\t7\t4\t2\t9\t5\t8\t3\t6"
test_case "${random_input_with_tabs}\t-\t1" "Error"
