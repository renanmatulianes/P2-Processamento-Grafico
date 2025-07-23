# Ray Tracing: Cena UFSCAR

Este projeto é uma implementação de um renderizador de *ray tracing* baseado nos conceitos do livro *"Ray Tracing in One Weekend"* de Peter Shirley. O código original foi modificado para gerar uma cena personalizada que exibe a palavra "UFSCAR" formada por esferas de diferentes materiais.

## Preview
![preview](https://github.com/renanmatulianes/P2-Processamento-Grafico/blob/release/ufscar.png)

## Descrição do Projeto

O objetivo foi criar uma cena visualmente interessante, utilizando o código base fornecido pelo livro. A cena final consiste em:
- Um plano que serve como chão.
- A palavra "UFSCAR", onde cada letra é composta por um conjunto de pequenas esferas.
- Materiais distintos para cada letra, incluindo difuso (`lambertian`), metálico (`metal`) e vidro (`dielectric`).
- Um campo de esferas menores, geradas aleatoriamente ao redor da palavra, para enriquecer o ambiente e produzir reflexos.
- Uma câmera configurada com um ângulo específico de forma a permitir a visualização da palavra formada.

## Requisitos Cumpridos

#### Seguimos o tutorial do livro*Ray Tracing in One Weekend*

#### Cena complexa com múltiplos materiais:
- **Letras com material `lambertian`:** As letras 'U' (azul), 'C' (vermelho) e 'R' (verde) possuem acabamento fosco.
- **Letras com material `metal`:** A letra 'F' (dourado) e 'A' (prata) são reflexivas, demonstrando reflexos especulares.
- **Letra com material `dielectric`:** A letra 'S' é feita de vidro, exibindo o efeito de refração da luz.
- Além disso, várias esferas com materiais variados foram espalhadas pelo chão.

#### Posição da câmera ajustada:
- A câmera foi posicionada de forma que permitisse a visualização da palavra "UFSCAR" inteiramente e centralizada.

## Como Compilar e Renderizar a Cena

### Pré-requisitos
Necessário um compilador C++ e o CMake instalados.

## Execução do Projeto

Para construir e executar o projeto, siga os passos abaixo.

```bash
# Configuração 1
$ cmake -B build

# Configuração 2
$ cmake --build build

# Compilar
$ cmake --build build --target inOneWeekend

# Renderizar cena
$ build/inOneWeekend > image.ppm
```

### Visualizando a Imagem
O arquivo gerado, `image.ppm`, é um formato de imagem ppm. Você pode abri-lo com uma variedade de programas, incluindo:
- **GIMP** (multiplataforma)
- **IrfanView** (Windows)
- **Preview** (macOS)
- Ou utilize um visualizador de imagem online, como [este](https://www.cs.rhodes.edu/welshc/COMP141_F16/ppmReader.html).

## Integrantes do Grupo

- Renan Matulianes Arnaldo
- Lucas Pereira Goes
- João Augusto Luvizotto
- Juan Pedro