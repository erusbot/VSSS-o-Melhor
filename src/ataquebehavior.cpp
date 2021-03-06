/*
 * ataquebehavior.cpp
 *
 *  Created on: 10 de dez de 2018
 *      Author: ERUS
 */

#include "ataquebehavior.h"

vsssERUS::AtaqueBehavior::AtaqueBehavior() {}

vsssERUS::AtaqueBehavior::~AtaqueBehavior() { return; }

vsssERUS::Ponto vsssERUS::AtaqueBehavior::movimenta(vsssERUS::Ponto posicao, vsssERUS::World* mundo){
    return vsssERUS::Ponto();
}

std::pair<int,int> vsssERUS::AtaqueBehavior::controle(vsssERUS::Ponto posicao, vsssERUS::World* mundo){
    return pair<int,int>();
}

std::pair<int,int> vsssERUS::AtaqueBehavior::sairDaParede(vsssERUS::Ponto posicao, vsssERUS::World* mundo) {
    return pair<int, int>();
}

std::pair<int,int> vsssERUS::AtaqueBehavior::evitarColisaoEntreJogadores(vsssERUS::Ponto posicao, vsssERUS::World* mundo) {
    return pair<int, int>();
}
