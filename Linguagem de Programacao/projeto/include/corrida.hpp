#ifndef _CORRIDA_HPP_
#define _CORRIDA_HPP_
#include "../include/sapos.hpp"
#include "../include/pista.hpp"
#include <string>
#include <vector>

/**
* Armazena os dados de uma pista.
* Armazena os sapos corredores.
* Exibe as estatísticas da corrida e dos sapos
* Lê arquivo CSV com os sapos e as corridas
*/
class Corrida{
	private:
		std::string nome;
		Pista *pista;
	public:
		Corrida();
		~Corrida();
		Corrida(std::string nome, Pista pista);
		std::vector<Sapo*> sapos;
		// Recupera os sapos do csv e insere no vector
		void inserirSapos(std::string nomeArquivo, std::string delimitador);
		void inserirPista(Pista &pista);
		void estatisticas();

};

#endif