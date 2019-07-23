#!/bin/bash

declare -a StringArray=("VSS-Core" "VSS-Simulator" "VSS-Viewer" "VSS-SampleCpp")

declare -a BoolArray=(false false false false false)

MAIN() {
	clear

	echo -e "Instalador VSS-Simulator\n"
	echo -e "Simulador by Rodetas e RobôCIn\n"
	echo -e "Script de instalação desenvolvido por ERUS\n"

	echo -e "Requisitos:\nCMAKE, git e boost instalados\n"

	echo -e "Lembre-se de rodar esse script com sudo!\n"

	echo -e "Pressione enter para continuar..."

	read

	clear

	echo "Deseja instalar o VSS-Simulator? (S/N)"

	read ans_inst

	if [ "$ans_inst" = "S" ] || [ "$ans_inst" = "s" ]; then
		echo
	else
		echo -e "Finalizando..."
		return 0
	fi

	clear

	ASK_INSTALL;

	DO_INSTALL;

	return 0
}

# Pergunta ao usuário quais sistemas ele deseja instalar
ASK_INSTALL() {
	declare iterator=0

	for val in ${StringArray[@]}; do
		echo "Deseja instalar $val?(S/N) - $iterator"
		read ans
		if [ "$ans" = "S" ] || [ "$ans" = "s" ]; then
			BoolArray[iterator]=true
			echo "install"
		else
			echo
		fi
		iterator=$((iterator+1))
		clear
	done
}


# Realiza a instalação de fato - TODO
DO_INSTALL() {
	for val in ${BoolArray[@]}; do
		echo "$val"
	done
}

MAIN;