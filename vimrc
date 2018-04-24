" All system-wide defaults are set in $VIMRUNTIME/debian.vim and sourced by
" the call to :runtime you can find below.  If you wish to change any of those
" settings, you should do it in this file (/etc/vim/vimrc), since debian.vim
" will be overwritten everytime an upgrade of the vim packages is performed.
" It is recommended to make changes after sourcing debian.vim since it alters
" the value of the 'compatible' option.

" This line should not be removed as it ensures that various options are
" properly set to work with the Vim-related packages available in Debian.
runtime! debian.vim

" Vim will load $VIMRUNTIME/defaults.vim if the user does not have a vimrc.
" This happens after /etc/vim/vimrc(.local) are loaded, so it will override
" any settings in these files.
" If you don't want that to happen, uncomment the below line to prevent
" defaults.vim from being loaded.
" let g:skip_defaults_vim = 1

" Uncomment the next line to make Vim more Vi-compatible
" NOTE: debian.vim sets 'nocompatible'.  Setting 'compatible' changes numerous
" options, so any other options should be set AFTER setting 'compatible'.
"set compatible

" Vim5 and later versions support syntax highlighting. Uncommenting the next
" line enables syntax highlighting by default.
if has("syntax")
  syntax on
endif

" If using a dark background within the editing area and syntax highlighting
" turn on this option as well
"set background=dark

" Uncomment the following to have Vim jump to the last position when
" reopening a file
"if has("autocmd")
"  au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g'\"" | endif
"endif

" Uncomment the following to have Vim load indentation rules and plugins
" according to the detected filetype.
"if has("autocmd")
"  filetype plugin indent on
"endif

" The following are commented out as they cause vim to behave a lot
" differently from regular Vi. They are highly recommended though.
"set showcmd		" Show (partial) command in status line.
"set showmatch		" Show matching brackets.
"set ignorecase		" Do case insensitive matching
"set smartcase		" Do smart case matching
"set incsearch		" Incremental search
"set autowrite		" Automatically save before commands like :next and :make
"set hidden		" Hide buffers when they are abandoned
"set mouse=a		" Enable mouse usage (all modes)

" Source a global configuration file if available
if filereadable("/etc/vim/vimrc.local")
  source /etc/vim/vimrc.local
endif
set nocompatible
syntax on
colo desert
set nu
set tabstop=4
set softtabstop=4
set shiftwidth=4
set cursorline
set cindent
set ruler
set expandtab
set clipboard=unnamed
set backspace=indent,eol,start
au BufNewFile *.cpp 0r lych.header

map <F9> :sil call DebugRun()<CR>
imap <F9> <Esc><F9>
map <F10> :sil call Run()<CR>
imap <F10> <Esc><F10>
map <F5> :sil call TestRun()<CR>
imap <F5> <Esc><F5>


function! Run()
	winc l
        winc k
	w
        winc h
	w
	only
	!(time ./%< <%<.in >%<.out)2>>%<.out
	bel vs %<.in
	bel sv %<.out
	winc h
	redr
	colo desert
endfunc
   

function! CompileRun()
     winc l
     winc k
     w
     winc h
     w
     only
     let v:statusmsg = ''
     make
     if empty(v:statusmsg)
	     call Run()
     else
	     cw
	     winc k
	     redr
	     colo desert
     endif
endfunc

function! DebugRun()
     if &filetype == "cpp"
         set makeprg=g++\ %\ -Wall\ -g\ -o\ %<\ -DLYCH
     elseif &filetype == "c"
         set makeprg=gcc\ %\ -Wall\ -g\ -o\ %<\ -DLYCH
     elseif &filetype == "cuda"
         set makeprg=nvcc\ %\ -o\ %<\ -DLYCH
     endif
     call CompileRun()
endfunc

function! TestRun()
	if &filetype == "cpp"
        set makeprg=g++\ %\ -Wall\ -O2\ -o\ %<
    elseif &filetype == "c"
        set makeprg=gcc\ %\ -Wall\ -O2\ -o\ %<
    elseif &filetype == "cuda"
        set makeprg=nvcc\ %\ -o\ %<
    endif
    call CompileRun()
endfunc

inoremap { {}<ESC>i

map <C-A> ggVG
map! <C-A> <Esc>ggVG
map <F12> gg=G
vmap <C-c> "+y
