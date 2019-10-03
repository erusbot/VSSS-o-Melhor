#ifndef CAMPO_H
#define CAMPO_H

#include <cstdio>
#include <cstdlib>
#include "teamplayer.h"
#include "team.h"
#include "ball.h"
#include <cstdlib>
#include <string>

class TeamPlayer;

// TODO: Atualizar as informações abaixo
/* Nome do módulo: Limite
		* Ano de criação: 2018/10
		* Descrição do módulo: Informações sobre os limites do campo
		* Versão: 1.1
		* tstado!! Selo Valdino de Garantia \0/
		* Pré-requisitos: Pontos distintos
		* Membros: Ricardo Ramos, Gabriel Valdino
*/

namespace vsssERUS{

// Constantes de discretização do campo

// Dimensões do VSSS (em cm)
#define VSSS_SIZE_X 7.5
#define VSSS_SIZE_Y 7.5
#define VSSS_SIZE_Z 7.5

// Dimensões do campo (em cm)
#define FIELD_SIZE_X 150
#define FIELD_SIZE_Y 130

/* 
 * Este define indica que será utilizado o próprio tamanho do VSSS como constante de 
 * discretização. Foi incluído aqui caso alguém precise alterar a forma como a discretização
 * é realizada futuramente. Caso seja o caso, vai ser necessário implementar o cálculo
 * novo na função apropriada no .cpp.
 *  
 */
#define USE_VSS_SIZE_AS_PARAM

class Campo
{
private:
	/* Nome do módulo: Limite
	* Ano de criação: 2018/10
	* Descrição do módulo: Informações sobre os limites do campo
	* Versão: 1.1
	* tstado!! Selo Valdino de Garantia \0/
	* Pré-requisitos: Pontos distintos
	* Membros: Ricardo Ramos, Gabriel Valdino
	*/

	class Limite
	{
		Ponto ponto1;
		Ponto ponto2;
	public:
		Limite(Ponto p1 = Ponto(0,0), Ponto p2 = Ponto(0,0));
		Ponto pontoMedio();
		double distancia();
		double distanciaParaOutroLimite(Limite outro);
		Ponto returnPonto(int x);
	};

	enum Lado {
		Esquerda,
		Direita
		};

	Limite limiteSuperior;
	Limite limiteInferior;
	Limite golDireito;
	Limite golEsquerdo;
	Limite limiteDireito;
	Limite limiteEsquerdo;
	Lado nossoLado;

	Team* friendlies;
	Team* enemies;

	Ball* ball;

	// Constantes de discretização do campo
	int disc_x, disc_y;

public:
	// Struct auxiliar para transmitir os dados posicionais para os teamPlayers
	struct dadosDoCampo {
		Ponto f1, f2, f3, e1, e2, e3, b;
	};

	pair<int, int> getDiscData() { return pair<int, int>(disc_x, disc_y);}

	dadosDoCampo& getPositions();
	Campo();
	Campo(char* campo);

	/* estaDentroDoCampo
	* Intenção da Função:
	* Pré-requisitos:
	* Efeitos colaterais:
	* Parâmetros:
	* Retorno:
	*/
	bool estaDentroDoCampo(Ponto posicao);

	/* campoPotencial
	* Intenção da Função:
	* Pré-requisitos:
	* Efeitos colaterais:
	* Parâmetros:
	* Retorno:
	*/
	double campoPotencial(TeamPlayer jogador);

	/* atualizarCampo
	* Intenção da Função:
	* Pré-requisitos:
	* Efeitos colaterais:
	* Parâmetros:
	* Retorno:
	*/
	void atualizarCampo(char* campo);

	/* getLado
	* Intenção da Função:
	* Pré-requisitos:
	* Efeitos colaterais:
	* Parâmetros:
	* Retorno:
	*/
	Lado getLado(){
		return this->nossoLado;
	}

	/* setLado
	* Intenção da Função:
	* Pré-requisitos:
	* Efeitos colaterais:
	* Parâmetros:
	* Retorno:
	*/
	void setLado(int x);

	/* getBordaSuperior
	* Intenção da Função:
	* Pré-requisitos:
	* Efeitos colaterais:
	* Parâmetros:
	* Retorno:
	*/
	int getBordaSuperior();

	/* getBordaInferior
	* Intenção da Função:
	* Pré-requisitos:
	* Efeitos colaterais:
	* Parâmetros:
	* Retorno:
	*/
	int getBordaInferior();

	/* getBordaEsquerda
	* Intenção da Função:
	* Pré-requisitos:
	* Efeitos colaterais:
	* Parâmetros:
	* Retorno:
	*/
	int getBordaEsquerda();

	/* getBordaDireita
	* Intenção da Função:
	* Pré-requisitos:
	* Efeitos colaterais:
	* Parâmetros:
	* Retorno:
	*/
	int getBordaDireita();

	/* getMeioDeCampo
	* Intenção da Função:
	* Pré-requisitos:
	* Efeitos colaterais:
	* Parâmetros:
	* Retorno:
	*/
	Ponto getMeioDeCampo();

	/* getMeioDeGolAliado
	* Intenção da Função:
	* Pré-requisitos:
	* Efeitos colaterais:
	* Parâmetros:
	* Retorno:
	*/
	Ponto getMeioDeGolAliado();

	/* getMeioDeGolInimigo
	* Intenção da Função:
	* Pré-requisitos:
	* Efeitos colaterais:
	* Parâmetros:
	* Retorno:
	*/
	Ponto getMeioDeGolInimigo();

	void setBall(Ball& b) { this->ball = &b; }

};
} // vsssERUS

#endif // CAMPO_H
