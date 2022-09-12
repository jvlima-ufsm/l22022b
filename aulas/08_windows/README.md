
# Suporte no Windows para C++

Há três alternativas para desenvolver os trabalhos em um ambiente Windows: WSL, máquinas virtuais ou MinGW.

## Windows WSL

O [WSL](https://docs.microsoft.com/pt-br/windows/wsl/about) funciona como um subsistema de virtualização nativo do Windows para suporte de binários Linux. 

Siga os passos abaixo:
- Primeiro, instale o WSL https://docs.microsoft.com/pt-br/windows/wsl/install
- Se comando `wsl` não é encontrado, siga https://docs.microsoft.com/pt-br/windows/wsl/install-manual
- Depois, instale uma distribuição Linux como o Ubuntu 20 na [Microsoft Store](https://aka.ms/wslstore)

Após instalação, o programa abrirá um terminal Linux da distribuição Ubuntu. Agora, devemos instalar os aplicativos básicos para integrar com o Visual Studio com [execução remota](https://code.visualstudio.com/docs/remote/wsl).

No Visual Studio, instale a extensões abaixo:
- [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
- [Remote - WSL](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-wsl)

No terminal Linux, instale os compiladores e bibliotecas necessários:
```
$ sudo apt update
$ sudo apt install build-essential valgrind libcaca-dev
```

No WSL as pastas do Windows ficam em `/mnt/c/`. Abra o Visual Studio dentro do WSL com o comando:
```
$ code 
```

Todos os comandos de compilação, depuração e execução funcionam no WSL. As janelas gráficas funcionam apenas a partir do Windows 11.

## Máquinas virtuais com VirtualBox

O VirtualBox é um software de virtualização suportado em vários sistemas. 

Baixe o VirtualBox no site oficial (https://www.virtualbox.org/wiki/Downloads).

A distribuição Linux recomendada é o Ubuntu e pode ser obtido de duas formas:
- Uma imagem pronta no site https://www.osboxes.org/ubuntu/
- Instalar o sistema do [site oficial](https://ubuntu.com/download/desktop), veja instruções em https://brb.nci.nih.gov/seqtools/installUbuntu.html

## MinGW

O [MinGW](https://www.msys2.org/) fornece ferramentas de software para ambiente Windows. Podemos instalar os principais compiladores e integrar como Visual Studio.

Os passos são descritos abaixo onde:
- MSYS2 em https://www.msys2.org/, principalmente o passo 7 que instala o compilador GCC.
- https://code.visualstudio.com/docs/cpp/config-mingw principalmente o passo 5 que adiciona a pasta `C:\msys64\mingw64\bin` no `PATH` do usuário.

Também podemos instalar a `libcaca` no MSYS2 com o comando:
```
pacman -S mingw-w64-x86_64-libcaca
```

Depois precisamos integrar o Visual Studio. Depois de adicionar o arquivo `tasks.json` como descrito
[aqui](https://code.visualstudio.com/docs/cpp/config-mingw), precisamos indicar o caminho da biblioteca instalada pelo MSYS2. Um exemplo de arquivo `tasks.json` segue abaixo seguindo os passos aqui descritos:
```json
{
	"version": "2.0.0",
	"tasks": [
		{
			"type": "cppbuild",
			"label": "C/C++: g++.exe arquivo de build ativo",
			"command": "C:\\msys64\\mingw64\\bin\\g++.exe",
			"args": [
				"-fdiagnostics-color=always",
				"-g",
				"-IC:\\msys64\\mingw64\\include",
				"${file}",
				"-o",
				"${fileDirname}\\${fileBasenameNoExtension}.exe",
				"-LC:\\msys64\\mingw64\\lib",
				"-lcaca"
			],
			"options": {
				"cwd": "${fileDirname}"
			},
			"problemMatcher": [
				"$gcc"
			],
			"group": {
				"kind": "build",
				"isDefault": true
			},
			"detail": "compilador: C:\\msys64\\mingw64\\bin\\g++.exe"
		}
	]
}
```

Note que as opções para o `g++` são semelhantes e indicam o caminho do `caca.h` em `C:\msys64\mingw64\include` e a biblioteca `caca.dll` em `C:\msys64\mingw64\lib` indicando a ligação na opção `-lcaca`.
