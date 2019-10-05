" LDC Syntax
" d3s

syn keyword LDCFunc bit input output word dword timer func
syn keyword LDCKeyword local static memory offdelay

syn match LDCComment '//.*$' display
syn match LDCPort '[<>]' display
syn match LDCInt '\d' display

syn region LDCFunctionReg start="{" end="}" fold transparent contains=LDCFunc,LDCKeyword,LDCComment,LDCPort

hi colorFuncKeyword ctermfg=9
hi colorComment ctermfg=10
hi colorInt ctermfg=11
hi colorPort ctermfg=14

hi def link LDCFunc colorFuncKeyword
hi def link LDCKeyword colorFuncKeyword
hi def link LDCComment colorComment
hi def link LDCPort colorPort
hi def link LDCInt colorInt

let b:current_syntax = "LDC"
