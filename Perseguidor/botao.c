/* Criar uma fun��o para criar o bot�o

struct botao{
	BITMAP*
	
	int x	- onde come�a
	int y	- onde come�a
	int x 	- onde termina
	int y	- onde termina
	//para delimitar o retangulo, o v�rticies opostos 

};

Criar fun��o para saber se clicou no espa�o delimitado do bot�o:
	passar como par�metro o x e y do mouse_b quabdo clica (mouse_b & 1) e o bot�o
		bitmap original = fundo preto
		depois que clica = muda o bitmap para o correspondente - acesso por ponteiro
	
Para o jogo da velha criar uma matriz, pra quando houver o clink naquela area do bot�oa
altera o valor da matriz para 10 ou 1 exemplo
	Se j� estiver com esses valores nao alterar mais 	- entra commo if antes da entrada para alterar 
		if(area == 10 || area == 1) { 'VAZIO' }
		else.... 	realiza as mudan�as de imagem e valor
		
		
*/

/*verifica��o de vitoria - fun��o e somar a cada jogada
	fun��o que retorna 9
	somar ate 9
		if(partida == 9)
			break();
		While(partida != 9) ...


*/

//bitmap pra X e pra O, usar o boneco e terran
//O break(); return 0; deu certo 
