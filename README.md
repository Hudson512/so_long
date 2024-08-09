# so_long
[Documentação da biblioteca minilibx](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)

<h1>Guia de uso da minilibx</h1>
<ol>
<li>Inicializar a bliblioteca:</li>

		#include <mlx.h>

		int	main(void)
		{
			void	*mlx;

			mlx = mlx_init();
		}
<p>
mlx_init() : Função que estabelecerá uma conexão com sistema gráfico correto e retornará um void * que contém a localização da nossa instância MLX atual
</p>
	
<li>Criando um janela:</li>

		#include <mlx.h>

		int	main(void)
		{
			void	*mlx;
			void	*mlx_win;

			mlx = mlx_init();
			mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
			mlx_loop(mlx);
		}
<p>
		mlx_new_window(): 
			Função usada para criar uma nova janela na tela após a inicialização da MiniLibX com a função mlx_init.

			Protótipo da função
				void *mlx_new_window(void *mlx_ptr, int width, int height, char *title);

			Parâmetros
				mlx_ptr (void *):
					Este é o ponteiro retornado por mlx_init(). Ele representa a instância da conexão com o sistema gráfico que você configurou anteriormente. É necessário para que a função saiba qual contexto gráfico usar para criar a nova janela.
			
				width (int):
					A largura da janela em pixels.
			
				height (int):
					A altura da janela em pixels.

				title (char *):
					O título da janela. Este é o texto que aparecerá na barra de título da janela.

			Retorno
				void *:
					A função retorna um ponteiro para a janela recém-criada. Esse ponteiro será usado em outras funções da MLX que precisam manipular essa janela, como a configuração de eventos ou a exibição de gráficos.

		mlx_loop():
			A função mlx_loop(mlx) é um componente essencial em qualquer aplicação gráfica que utiliza a MiniLibX (MLX). Ela é responsável por manter a aplicação ativa e responder a eventos como cliques do mouse, pressionamento de teclas, ou atualizações gráficas.

			Protótipo da função
				int mlx_loop(void *mlx_ptr);

			Parâmetros
				mlx_ptr (void *):
					Este é o ponteiro retornado pela função mlx_init(). Ele representa a conexão atual com o sistema gráfico e é usado para manter a aplicação dentro de um loop de eventos.
			Retorno
				int:
					Em muitos casos, essa função nunca retorna, porque ela mantém o programa em execução contínua. Se ela retornar, normalmente será um valor inteiro, que pode indicar um erro ou que o loop foi terminado manualmente.
</p>
</ol>
