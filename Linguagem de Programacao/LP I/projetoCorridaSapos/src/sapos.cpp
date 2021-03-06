#include "../include/sapos.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

// Construtores
Sapo::Sapo(){}
Sapo::~Sapo(){}

/**
* @brief Construtor responsável por inicializar um sapo com seu nome, identificador e pulo máximo (forcaPulo). Os demais atributos também são inicializados como zero.
* @param std::string nome
* @param std::string identificador
* @param int forcaPulo
*/
Sapo::Sapo(std::string nome, std::string identificador, int forcaPulo){
	this->identificador = identificador;
	this->nome = nome;
	this->forcaPulo = forcaPulo;

	this->empates = 0;
	this->vitorias = 0;
	this->derrotas = 0;
	this->quantPuloDados = 0;
	this->distanciaPercorrida = 0;
	this->quantProvasDisputadas = 0;

}

/**
* @brief Calcula aleatoriamente um valor de 1 até a maior distancia que um sapo pode pular e soma isso a distancia percorrida pelo sapo.
*/
void Sapo::pular(){
	// Gera numero aleatorio entre 1 e a distancia do pulo
	// que um sapo pode dar
	int pulo = (std::rand() % getForcaPulo()) + 1;

	this->distanciaPercorrida += pulo;

	std::cout << "Nome: " 		   	   << this->nome 		  << std::endl
		      << "Identificador: " 	   << this->identificador << std::endl
			  << "Pulou: " 			   << pulo  			  << std::endl
			  												  << std::endl;

	this->quantPuloDados++;
}

/**
* @brief Sobrecarga de ostream, exibe as informações de um objeto sapo
* @param std::ostream &o
* @param Sapo &sapo
* @return std::ostream &o
*/
std::ostream& operator<< (std::ostream &o, Sapo &sapo){
    o <<
                                		      	                  		 std::endl <<
    "Nome: "					     	<< sapo.nome        		  << std::endl <<
    "Identificador: " 				 	<< sapo.identificador 		  << std::endl <<
    "Força do Pulo: " 				 	<< sapo.forcaPulo         	  << std::endl <<
    "Quantidade de pulos dados: "    	<< sapo.quantPuloDados        << std::endl <<
                                        							     std::endl;

    return o;
}

/**
* @brief Insere o nome do sapo
* @param std::string nome
*/
void Sapo::setNome(std::string nome){
    this->nome = nome;
}

/**
* @brief Insere o identificador do sapo
* @param std::string identificador
*/
void Sapo::setIdentificador(std::string identificador){
    this->identificador = identificador;
}

/**
* @brief Insere o pulo máximo do sapo
* @param int forca
*/
void Sapo::setForcaPulo(int forca){
	forcaPulo = forca;
}

/**
* @brief Recupera o pulo máximo do sapo
* @return int forcaPulo
*/
int Sapo::getForcaPulo(){
	return forcaPulo;
}

/**
* @brief Recupera a distancia percorrida pelo sapo
* @return int distanciaPercorrida
*/
int Sapo::getDistanciaPercorrida(){
	return this->distanciaPercorrida;
}

/**
* @brief Insere o ranking atual do sapo na corrida
* @param int rankingAtual
*/
void Sapo::setRankingAtual(int rankingAtual){
    this->rankingAtual = rankingAtual;
}

/**
* @brief Recupera o ranking do sapo na corrida
* @return int rankingAtual
*/
int Sapo::getRankingAtual(){
    return this->rankingAtual;
}

/**
* @brief Insere a quantidade de provas disputadas pelo sapo
* @param int provasDisputadas
*/
void Sapo::setQuantProvasDisputadas(int quantProvasDisputadas){
    this->quantProvasDisputadas = quantProvasDisputadas;
}

/**
* @brief Recupera a quantidade de provas disputadas pelo sapo
* @return int quantProvasDisputadas
*/
int Sapo::getQuantProvasDisputadas(){
    return this->quantProvasDisputadas;
}

/**
* @brief Insere a distancia percorrida pelo sapo
* @param int distanciaCorrida
*/
void Sapo::setDistanciaPercorrida(int distanciaPercorrida){
    this->distanciaPercorrida = distanciaPercorrida;
}

/**
* @brief Insere a quantidade de vitorias do sapo
* @param int vitorias
*/
void Sapo::setVitorias(int vitorias){
	this->vitorias = vitorias;
}

/**
* @brief Recupera a quantidade de vitorias do sapo
* @return int vitorias
*/
int Sapo::getVitorias(){
	return this->vitorias;
}

/**
* @brief Insere a quantidade de derrotas do sapo
* @param int derrotas
*/
void Sapo::setDerrotas(int derrotas){
	this->derrotas = derrotas;
}

/**
* @brief Recupera a quantidade de derrotas do sapo
* @return int derrotas
*/
int Sapo::getDerrotas(){
	return this->derrotas;
}

/**
* @brief Recupera o nome do sapo
* @return std::string nome
*/
std::string Sapo::getNome(){
	return this->nome;
}

/**
* @brief Recupera o nome do sapo
* @return std::string nome
*/
std::string Sapo::getIdentificador(){
	return this->identificador;
}
