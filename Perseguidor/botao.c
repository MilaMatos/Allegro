/* Criar uma função para criar o botão

struct botao{
	BITMAP*
	
	int x	- onde começa
	int y	- onde começa
	int x 	- onde termina
	int y	- onde termina
	//para delimitar o retangulo, o vérticies opostos 

};

Criar função para saber se clicou no espaço delimitado do botão:
	passar como parâmetro o x e y do mouse_b quabdo clica (mouse_b & 1) e o botão
		bitmap original = fundo preto
		depois que clica = muda o bitmap para o correspondente - acesso por ponteiro
	
Para o jogo da velha criar uma matriz, pra quando houver o clink naquela area do botãoa
altera o valor da matriz para 10 ou 1 exemplo
	Se já estiver com esses valores nao alterar mais 	- entra commo if antes da entrada para alterar 
		if(area == 10 || area == 1) { 'VAZIO' }
		else.... 	realiza as mudanças de imagem e valor
		
		
*/

/*verificação de vitoria - função e somar a cada jogada
	função que retorna 9
	somar ate 9
		if(partida == 9)
			break();
		While(partida != 9) ...


*/

//bitmap pra X e pra O, usar o boneco e terran
//O break(); return 0; deu certo 
