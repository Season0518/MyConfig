"Config For Vim&NeoVim

"Functions
function! Cond(Cond, ...)
  let opts = get(a:000, 0, {})
  return a:Cond ? opts : extend(opts, { 'on': [], 'for': [] })
endfunction

func SkipPair()  
    if getline('.')[col('.') - 1] == ')' || getline('.')[col('.') - 1] == ']' || getline('.')[col('.') - 1] == '"' || getline('.')[col('.') - 1] == "'" || getline('.')[col('.') - 1] == '}'  
        return "\<ESC>la"  
    else  
        return "\t"  
    endif  
endfunc  

"Plugins
call plug#begin(has('nvim') ? stdpath('data') . '/plugged' : '~/.vim/plugged')
	"Global Support
	Plug 'yuexiahu/vim-im-select'
	Plug 'preservim/nerdcommenter'

	" VSCODE Support
	Plug 'asvetliakov/vim-easymotion', Cond(exists('g:vscode'), { 'as': 'vsc-easymotion' })
	
	" Original NeoVim
	Plug 'itchyny/lightline.vim', Cond(!exists('g:vscode'))
	Plug 'easymotion/vim-easymotion', Cond(!exists('g:vscode'))
	Plug 'kaicataldo/material.vim', Cond(!exists('g:vscode'),{ 'branch': 'main' })
call plug#end()

"Global Support
set clipboard=unnamed
let g:mapleader = ','
let g:NERDCreateDefaultMappings = 1
let g:NERDSpaceDelims = 1
map <Leader> <Plug>(easymotion-prefix)

" Original Neovim
if !exists('g:vscode')
	set noshowmode
	set softtabstop=4
	set tabstop=4
	set shiftwidth=4
	set cindent
	set number
	set relativenumber
	set autoindent
	set background=dark
	let g:material_terminal_italics = 1
	let g:material_theme_style = 'palenight-community'
	colorscheme material
	:inoremap <TAB> <c-r>=SkipPair()<CR>
endif
