include irvine32.inc
BUFFER_SIZE = 5000
.Data
Index Byte 1
Key Byte ?
Promp11 Byte "GENERIC SORTING",0
Prompt12 Byte "===============",0
Sort1 Byte "SORT INTEGERS",0
Sort2 Byte "SORT CHARACTERS",0
Sort3 Byte "SORT WORDS/SENTENCES",0
Sort4 Byte "SORT STRINGS",0
Exitt Byte "EXIT",0

Prompt BYTE "Please Enter The Strings To Be Sorted: ",0
Prompt1 BYTE "Please Enter The Number Of Inputs To Be Sorted: ",0
Prompt2 BYTE "Result After Sorting: ",0
Input0 Byte "TAKE INPUT FROM USER",0
Input1 Byte "TAKE INPUT FROM FILE",0

;String Sort Data
Arr1 Byte 100 DUP(?)
Arr2D Byte 1000 DUP(?)
Str_array DWORD 100 DUP(?)
Row DWORD 100
Column DWORD 0
COUNT DWORD 0
Swap Byte 0

;String Sort File
fileee byte "INPUT FILE : ",0
fileee1 byte "OUTPUT STORED IN OUTPUT FILE",0
content BYTE 256 dup(?),0
temp BYTE 16 dup (?),0
smallest Byte 16 dup ('?'),0
target byte " ",0
countt byte 0 
start dword 0
current dword 0
end1 Dword 0
ascending byte 256 dup (?),0
stindex dword 0

filename2 BYTE "Output_File.txt",0
buffer BYTE 500 DUP(?)
fileHandle dword ?
filename BYTE "Input_File.txt",0
CRR byte 13
LF byte 10


;Integer Sort Data
array SDword 100 DUP(?)
Num_Elements Dword ?
var   SDword ? ;used to swap
var1  SDword 0    ; flag variable (to avoid error)
var2  SDword 1    ; flag variable (to avoid error)


;Character Sort Data
PArray Byte 100 DUP(?)
Counter Dword ?
var0   Byte ? ;used to swap

;WORD SORT DATA
Num_Word Dword ? ;number of word 
Array_STR Dword 100 DUP(?)
ARRAY2D byte 1000 DUP(?)
INN DWORD 0

.Code
Main Proc

Call INTRO
Call HomePage

cmp index,1
jne elsee_if
Call User_Interface

elsee_if:
cmp index,2
jne elsee
mov index,1
Call File_Interface

elsee:
mov ecx,10
ENDING_PROCESS:
Call Crlf
LOOP ENDING_PROCESS
Invoke ExitProcess,0

Main Endp


SORT_STRING PROC

call clrscr
;GETTING INPUT FROM USER
mov edx,offset prompt
call writestring
MOV ECX,100 
mov edx , offset arr1 
call readstring

;BREAKING STRING INTO WORDS WHEN FOUND SPACE OR NULL CHARACTER AND PUTTING IT IN 2D ARRAY
MOV ECX,100
MOV ESI,OFFSET ARR1
MOV EDI,OFFSET ARR2D

L2: ;ouuter loop

L1: ;inner loop
MOV BL,[ESI]
CMP BL,32 ;break when found space
JE NEXT
CMP BL,0 ;break when found null character
JE NEXT
MOV AL,[ESI]
MOV [EDI],AL
INC ESI
INC EDI
INC COUNT
DEC ECX
JMP L1

NEXT:
INC COLUMN
INC ESI
ADD EDI,ROW
SUB EDI,COUNT
MOV COUNT,0
CMP BL,0 ;WHEN END OF STRING FOUND THEN BREAK THE LOOP
JE DOWN
JMP L2

DOWN:

; putting offsets of breaked string in str_array to perform sort on it
mov ecx,column
mov eax,0
mov esi,offset arr2D
mov edi,offset str_array
breaking: 
mov edx,esi
mov [edi],edx
add edi,4
add esi,100
loop breaking

dec column ;NUMBER OF TIMES TO PERFORM SORT

       ; Strings are all loaded into memory, time to sort
BEGIN_SORT:
       MOV swap, 0                       ; Flag for if we make a swap this pass
       MOV EAX, 0                        ; Current string in str_array

COMPARE_LOOP:
; Loads two string addresses to compare into registers
       MOV EDX, [str_array + EAX * 4]   
       INC EAX
       MOV ECX, [str_array + EAX * 4]

       MOV EBX, 0                        ; Initial location in string
STR_CMP:
; Pull off a byte from the string and load it into EDI
       MOVZX EDI, BYTE PTR [EDX + EBX]         

; If we hit the end of the first string here, assume we are less than the other string
CMP EDI, 0
       JE LESS_THAN
       MOVZX ESI, BYTE PTR [ECX + EBX] ; Same thing, but for ESI
       CMP ESI, 0           ; If we hit the end of the second string here, assume we are greater than
       JE GREATER_THAN
       CMP EDI, ESI         ; Else we just do a comparison on the ASCII value of the indexed character in the string
       JL LESS_THAN
       JG GREATER_THAN
       INC EBX              ; Both characters are equal, move to the next one in the strings and do it again
       JMP STR_CMP
LESS_THAN:
       JMP CHECK_END_SORT   ; If the first string is less than the second, they are in order, no swapping needed
GREATER_THAN:
       DEC EAX
       MOV [str_array + EAX * 4], ECX
       INC EAX
       MOV [str_array + EAX * 4], EDX ; Swap entries
       MOV swap, 1
CHECK_END_SORT:
       CMP EAX,column
       JNE COMPARE_LOOP     ; We are not at the end of str_array yet, loop again with next two elements

       ; If we are here, we are at end of str_array
       CMP [swap], 0
       JNE BEGIN_SORT       ; If we made a swap in this pass of str_array, do another pass from the very beginning

       ; END OF SORTING

	   ;WRITING SORTED STRING
	   call crlf
	   inc column
	   MOV EDX,OFFSET PROMPT2
	   CALL WRITESTRING
	   CALL CRLF
       MOV ECX,column	; Number of strings to display
       MOV EAX,0		; Current string to dislay
WRITE_STRINGS:
       MOV EDX, [str_array + EAX * 4]
       CALL WriteString
       Call Crlf
       INC EAX
       LOOP WRITE_STRINGS


mov count,0
mov column,0
mov eax,0
mov ecx,100
mov esi,offset arr1
mov edi,offset str_array
DONEE:
mov [esi],eax
mov [edi],eax
inc esi
inc edi
LOOP DONEE

mov ecx,1000
mov edi,offset arr2D
DONE1:
mov [edi],eax
inc edi
LOOP DONE1


call crlf
call waitmsg
ret
SORT_STRING ENDP

HomePage PROC
call clrscr

mov ecx,80
mov dl,10
mov dh,4
LOOPS:
call gotoxy
mov al,42
call writechar
inc dl
LOOP LOOPS

mov ecx,20
dec dl
inc dh
LOOPSS:
call gotoxy
mov al,42
call writechar
inc dh
LOOP LOOPSS

mov ecx,80
LOOPPSS:
call gotoxy
mov al,42
call writechar
dec dl
LOOP LOOPPSS


mov ecx,22
mov dh,4
mov dl,10
LOOPPSSS:
call gotoxy
mov al,42
call writechar
inc dh
LOOP LOOPPSSS

whilee:

mov eax,15
call SetTextColor

mov dh,7
mov dl,35
call gotoxy
mov edx,offset promp11
call writestring

mov dh,8
mov dl,35
call gotoxy
mov edx,offset prompt12
call writestring

mov eax,15
call SetTextColor


cmp index,1
jne next
mov eax,12
call SetTextColor
next:
mov dh,10
mov dl,35
call gotoxy
mov edx,offset input0
call writestring


mov eax,15
call SetTextColor


cmp index,2
jne next1
mov eax,12
call SetTextColor
next1:

mov dh,12
mov dl,35
call gotoxy
mov edx,offset input1
call writestring


mov eax,15
call SetTextColor

cmp index,3
jne next13
mov eax,12
call SetTextColor
next13:

mov dh,14
mov dl,35
call gotoxy
mov edx,offset exitt
call writestring

mov eax,15
call SetTextColor


mov dh,16
mov dl,35
call gotoxy
call readchar

cmp eax,18432
jne down
dec index
down:
cmp eax,20480
jne up
inc index
up:
cmp index,4
jne loww
mov index,1
loww:
cmp index,0
jne lowww
mov index,3
lowww:
cmp al,13
jne whilee


call crlf
ret
HomePage ENDP

Intro Proc

Call Clrscr

mov eax,11
call SetTextColor

mov ecx,80
mov dl,10
mov dh,4
LOOPS:
call gotoxy
mov al,42
call writechar
inc dl
LOOP LOOPS

mov ecx,20
dec dl
inc dh
LOOPSS:
call gotoxy
mov al,42
call writechar
inc dh
LOOP LOOPSS

mov ecx,80
LOOPPSS:
call gotoxy
mov al,42
call writechar
dec dl
LOOP LOOPPSS


mov ecx,22
mov dh,4
mov dl,10
LOOPPSSS:
call gotoxy
mov al,42
call writechar
inc dh
LOOP LOOPPSSS


mov eax,10
call SetTextColor

mov dl,40
mov dh,13
call gotoxy
mov edx,offset promp11
call writestring

mov eax,14
call SetTextColor


mov dl,40
mov dh,14
call gotoxy
mov edx,offset prompt12
call writestring

mov eax,15
call SetTextColor


mov ecx,13
CR:
call crlf
LOOP CR
call waitmsg
ret
Intro Endp


User_Interface Proc
call clrscr

mov ecx,80
mov dl,10
mov dh,4
LOOPS:
call gotoxy
mov al,42
call writechar
inc dl
LOOP LOOPS

mov ecx,20
dec dl
inc dh
LOOPSS:
call gotoxy
mov al,42
call writechar
inc dh
LOOP LOOPSS

mov ecx,80
LOOPPSS:
call gotoxy
mov al,42
call writechar
dec dl
LOOP LOOPPSS


mov ecx,22
mov dh,4
mov dl,10
LOOPPSSS:
call gotoxy
mov al,42
call writechar
inc dh
LOOP LOOPPSSS


whilee:

mov eax,15
call SetTextColor

mov dh,7
mov dl,35
call gotoxy
mov edx,offset promp11
call writestring

mov dh,8
mov dl,35
call gotoxy
mov edx,offset prompt12
call writestring

mov eax,15
call SetTextColor


cmp index,1
jne next
mov eax,12
call SetTextColor
next:
mov dh,10
mov dl,35
call gotoxy
mov edx,offset Sort1
call writestring


mov eax,15
call SetTextColor


cmp index,2
jne next1
mov eax,12
call SetTextColor
next1:

mov dh,12
mov dl,35
call gotoxy
mov edx,offset Sort2
call writestring


mov eax,15
call SetTextColor


cmp index,3
jne next11
mov eax,12
call SetTextColor
next11:

mov dh,14
mov dl,35
call gotoxy
mov edx,offset Sort3
call writestring


mov eax,15
call SetTextColor


cmp index,4
jne next12
mov eax,12
call SetTextColor
next12:

mov dh,16
mov dl,35
call gotoxy
mov edx,offset Sort4
call writestring


mov eax,15
call SetTextColor


mov eax,15
call SetTextColor


cmp index,5
jne next13
mov eax,12
call SetTextColor
next13:

mov dh,18
mov dl,35
call gotoxy
mov edx,offset exitt
call writestring

mov eax,15
call SetTextColor


mov dh,20
mov dl,35
call gotoxy
call readchar

cmp eax,18432
jne down
dec index
jmp up
down:
cmp eax,20480
jne up
inc index
up:
cmp index,6
jne loww
mov index,1
loww:
cmp index,0
jne lowww
mov index,5
lowww:
cmp al,13
jne whilee

cmp index,1
jne character
call Integer_Sort
call User_Interface 
jmp ending

character:
cmp index,2
jne WORDD
call Character_Sort
call User_Interface 
jmp ending

WORDD:
cmp index,3
jne STRINGSS
CALL WORD_SORT
call User_Interface 
jmp ending

Stringss:
cmp index,4
jne endss
call SORT_STRING
call User_Interface 
jmp ending

endss:
cmp index,5
jne ending
mov index,1
call HomePage

ending:
call crlf
ret
User_Interface Endp

File_Interface Proc
call clrscr


mov ecx,80
mov dl,10
mov dh,4
LOOPS:
call gotoxy
mov al,42
call writechar
inc dl
LOOP LOOPS

mov ecx,20
dec dl
inc dh
LOOPSS:
call gotoxy
mov al,42
call writechar
inc dh
LOOP LOOPSS

mov ecx,80
LOOPPSS:
call gotoxy
mov al,42
call writechar
dec dl
LOOP LOOPPSS


mov ecx,22
mov dh,4
mov dl,10
LOOPPSSS:
call gotoxy
mov al,42
call writechar
inc dh
LOOP LOOPPSSS


whilee:

mov eax,15
call SetTextColor

mov dh,7
mov dl,35
call gotoxy
mov edx,offset promp11
call writestring

mov dh,8
mov dl,35
call gotoxy
mov edx,offset prompt12
call writestring

mov eax,15
call SetTextColor


cmp index,1
jne next
mov eax,12
call SetTextColor
next:
mov dh,10
mov dl,35
call gotoxy
mov edx,offset Sort1
call writestring


mov eax,15
call SetTextColor


cmp index,2
jne next1
mov eax,12
call SetTextColor
next1:

mov dh,12
mov dl,35
call gotoxy
mov edx,offset Sort2
call writestring


mov eax,15
call SetTextColor


cmp index,3
jne next11
mov eax,12
call SetTextColor
next11:

mov dh,14
mov dl,35
call gotoxy
mov edx,offset Sort3
call writestring


mov eax,15
call SetTextColor


cmp index,4
jne next12
mov eax,12
call SetTextColor
next12:

mov dh,16
mov dl,35
call gotoxy
mov edx,offset Sort4
call writestring


mov eax,15
call SetTextColor


mov eax,15
call SetTextColor


cmp index,5
jne next13
mov eax,12
call SetTextColor
next13:

mov dh,18
mov dl,35
call gotoxy
mov edx,offset exitt
call writestring

mov eax,15
call SetTextColor


mov dh,20
mov dl,35
call gotoxy
call readchar

cmp eax,18432
jne down
dec index
jmp up
down:
cmp eax,20480
jne up
inc index
up:
cmp index,6
jne loww
mov index,1
loww:
cmp index,0
jne lowww
mov index,5
lowww:
cmp al,13
jne whilee

cmp index,1
jne character
call Integer_Sort_FILE
call FILE_Interface 
jmp ending

character:
cmp index,2
jne WORDD
call Character_Sort_FILE

mov al,0
mov ecx,256
mov esi,offset content
mov edi,offset ascending
NULLING:
mov [esi],al
mov [edi],al
inc esi
inc edi
loop NULLING


mov ecx,16
mov al,0
mov esi,offset temp
mov edi,offset smallest
NULLING1:
mov [esi],al
mov [edi],al
inc esi
inc edi
LOOP NULLING1

call FILE_Interface 
jmp ending

WORDD:
cmp index,3
jne STRINGSS
CALL WORD_SORT_FILE

mov al,0
mov ecx,256
mov esi,offset content
mov edi,offset ascending
NULLINGx:
mov [esi],al
mov [edi],al
inc esi
inc edi
loop NULLINGx


mov ecx,16
mov al,0
mov esi,offset temp
mov edi,offset smallest
NULLING11:
mov [esi],al
mov [edi],al
inc esi
inc edi
LOOP NULLING11

call FILE_Interface 
jmp ending

Stringss:
cmp index,4
jne endss
call SORT_STRING_FILE
call WaitMsg

mov al,0
mov ecx,256
mov esi,offset content
mov edi,offset ascending
NULLING0:
mov [esi],al
mov [edi],al
inc esi
inc edi
loop NULLING0


mov ecx,16
mov al,0
mov esi,offset temp
mov edi,offset smallest
NULLING12:
mov [esi],al
mov [edi],al
inc esi
inc edi
LOOP NULLING12

call File_Interface 
jmp ending

endss:
cmp index,5
jne ending
mov index,1
call HomePage

ending:

call crlf
ret
File_Interface Endp

INTEGER_SORT Proc

Call Clrscr
Mov Edx,Offset Prompt1
Call WriteString
Call ReadDec
Mov Num_Elements,Eax
Mov Ecx,Num_Elements

mov esi,offset array
Insert:
call readint
mov [esi],eax
add esi,4
LOOP Insert

 ; initialing registers
    mov ebx,0
    mov eax,0
    mov esi,0
	mov edx,0
    mov ecx,Num_Elements
        
        
    l:
        mov eax,ecx ;j
        mov ebx,ecx ;i
        dec eax ; j = i  - 1
        mov ecx , eax
        ;dec eax
        cmp var2 ,ecx ; to avoid infinte loop when ecx = 0
        jg m 
        
        l2:
            mov edx , array[ebx* TYPE array - 4] ; value at [i]
            mov var,edx
            mov edx,array[eax* TYPE array - 4 ] ; value at [i-1]
            
            
            cmp edx,var
            jg l1    ;jump to swap
            jmp x    ; to avoid using swap algo
            ; SWAP
            l1:
                ;dec ecx
                mov array[ebx* TYPE array -4],edx
                mov edx,var
                mov array[eax* TYPE array - 4],edx
            jmp x    ; useless
            x:

            dec eax ; j = j - 1
        loop l2
        ;cmp var1,ebx   TO avoid error but seem useless
        ;jg m
        mov ecx,ebx ; retrive i
        
    loop l
    m:
 call crlf
 mov edx,offset prompt2
 call writestring
 call crlf
 
 mov ecx,Num_Elements
 mov edi,offset array
 Print:
 mov eax,[edi]
 call writeint
 add edi,4
 call crlf
 loop Print
 call crlf
 call waitmsg
ret
INTEGER_SORT Endp



CHARACTER_SORT Proc

Call Clrscr
Mov Edx,Offset Prompt1
Call WriteString
Call ReadDec
Mov Counter,Eax

Mov Ecx,Counter
mov esi,offset PArray
Insert:
Call Readchar
call writechar
call crlf
mov [esi],al
inc esi
LOOP Insert
mov ecx,Counter



    mov ebx,0
    mov eax,0
    mov esi,0 
        
    l:
        mov eax,ecx ;j
        mov ebx,ecx ;i
        dec eax ; j = i  - 1
        mov ecx , eax
        ;dec eax
        cmp var2 ,ecx ; to aoid infinte loop when ecx = 0
        jg m 
        
        l2:
            mov dl , parray[ebx* TYPE parray - 1] ; value at [i]
            mov var0,dl
            mov dl,parray[eax* TYPE parray - 1 ] ; value at [i-1]
            
            
            cmp dl,var0
            jg l1    ;jump to swap
            jmp x    ; to avoid using swap algo
            ; SWAP
            l1:
                ;dec ecx
                mov parray[ebx* TYPE parray -1],dl
                mov dl,var0
                mov parray[eax* TYPE parray - 1],dl
            jmp x    ; useless
            x:

            dec eax ; j = j - 1
        loop l2
        ;cmp var1,ebx   TO avoid error but seem useless
        ;jg m
        mov ecx,ebx ; retrive i
        
    loop l
    m:

	call crlf
	mov edx,offset prompt2
	call writestring
	call crlf


	mov esi,offset parray
	mov ecx,Counter
    print:
	mov al,[esi]
	call writeCHAR
	inc esi
	call crlf
	loop print
	call crlf
	call waitmsg
ret
CHARACTER_SORT Endp

WORD_SORT PROC

call clrscr
mov inn,0
;GETTING INPUT FROM USER
mov edx,offset prompt1
call writestring
CALL READDEC
mov NUM_WORD,EAX
mov ebx,num_word


MOV EDX,OFFSET ARRAY2D
MOV EDI,OFFSET ARRAY_STR

L1:
MOV ECX,100
CALL READSTRING
mov [EDI],EDX
add edx,100
add EDI,4
inc inn
cmp inn,ebx
jne L1

dec NUM_WORD ;NUMBER OF TIMES TO PERFORM SORT

       ; Strings are all loaded into memory, time to sort
BEGIN_SORT:
       MOV swap, 0                       ; Flag for if we make a swap this pass
       MOV EAX, 0                        ; Current string in str_array

COMPARE_LOOP:
; Loads two string addresses to compare into registers
       MOV EDX, [array_str + EAX * 4]   
       INC EAX
       MOV ECX, [array_str + EAX * 4]

       MOV EBX, 0                        ; Initial location in string
STR_CMP:
; Pull off a byte from the string and load it into EDI
       MOVZX EDI, BYTE PTR [EDX + EBX]         

; If we hit the end of the first string here, assume we are less than the other string
CMP EDI, 0
       JE LESS_THAN
       MOVZX ESI, BYTE PTR [ECX + EBX] ; Same thing, but for ESI
       CMP ESI, 0           ; If we hit the end of the second string here, assume we are greater than
       JE GREATER_THAN
       CMP EDI, ESI         ; Else we just do a comparison on the ASCII value of the indexed character in the string
       JL LESS_THAN
       JG GREATER_THAN
       INC EBX              ; Both characters are equal, move to the next one in the strings and do it again
       JMP STR_CMP
LESS_THAN:
       JMP CHECK_END_SORT   ; If the first string is less than the second, they are in order, no swapping needed
GREATER_THAN:
       DEC EAX
       MOV [array_str + EAX * 4], ECX
       INC EAX
       MOV [array_str + EAX * 4], EDX ; Swap entries
       MOV swap, 1
CHECK_END_SORT:
       CMP EAX,NUM_WORD
       JNE COMPARE_LOOP     ; We are not at the end of str_array yet, loop again with next two elements

       ; If we are here, we are at end of str_array
       CMP [swap], 0
       JNE BEGIN_SORT       ; If we made a swap in this pass of str_array, do another pass from the very beginning

       ; END OF SORTING

	   ;WRITING SORTED STRING
	   call crlf
	   inc NUM_WORD
	   MOV EDX,OFFSET PROMPT2
	   CALL WRITESTRING
	   CALL CRLF
       MOV ECX,NUM_WORD	; Number of strings to display
       MOV EAX,0		; Current string to dislay
WRITE_SORTED_WORDS:
       MOV EDX, [array_str + EAX * 4]
       CALL WriteString
       Call Crlf
       INC EAX
       LOOP WRITE_SORTED_WORDS

mov eax,0
mov ecx,1000
mov edi,offset array2D
DONE12:
mov [edi],eax
inc edi
LOOP DONE12

mov ecx,100
mov edi,offset array_str
DON:
MOV [edi],eax
inc edi
LOOP DON

call crlf
call waitmsg
ret
WORD_SORT ENDP

INTEGER_SORT_FILE Proc

Call Clrscr

mov edx,offset fileee
call writestring
mov edx , OFFSET filename
call OpenInputFile
mov fileHandle,eax

mov edx,OFFSET buffer
mov ecx,BUFFER_SIZE
call ReadFromFile

mov buffer[eax],0

mov edx,OFFSET buffer ; display the buffer
call WriteString
call Crlf

mov eax,fileHandle
call CloseFile

mov esi,offset buffer

call waitmsg

 ; initialing registers
    mov ebx,0
    mov eax,0
    mov esi,0
	mov edx,0
    mov ecx,Num_Elements
        
        
    l:
        mov eax,ecx ;j
        mov ebx,ecx ;i
        dec eax ; j = i  - 1
        mov ecx , eax
        ;dec eax
        cmp var2 ,ecx ; to avoid infinte loop when ecx = 0
        jg m 
        
        l2:
            mov edx , array[ebx* TYPE array - 4] ; value at [i]
            mov var,edx
            mov edx,array[eax* TYPE array - 4 ] ; value at [i-1]
            
            
            cmp edx,var
            jg l1    ;jump to swap
            jmp x    ; to avoid using swap algo
            ; SWAP
            l1:
                ;dec ecx
                mov array[ebx* TYPE array -4],edx
                mov edx,var
                mov array[eax* TYPE array - 4],edx
            jmp x    ; useless
            x:

            dec eax ; j = j - 1
        loop l2
        ;cmp var1,ebx   TO avoid error but seem useless
        ;jg m
        mov ecx,ebx ; retrive i
        
    loop l
    m:
 call crlf
 mov edx,offset prompt2
 call writestring
 call crlf
 
 mov ecx,Num_Elements
 mov edi,offset array
 Print:
 mov eax,[edi]
 call writeint
 add edi,4
 call crlf
 loop Print
 call crlf
 call waitmsg
ret
INTEGER_SORT_FILE Endp



CHARACTER_SORT_FILE Proc
local tcx:dword

call clrscr
mov edx,offset fileee
call writestring
mov edx , OFFSET filename
call OpenInputFile
mov fileHandle,eax

mov edx,OFFSET buffer
mov ecx,BUFFER_SIZE
call ReadFromFile

mov buffer[eax],0

mov edx,OFFSET buffer ; display the buffer
call WriteString
call Crlf

mov eax,fileHandle
call CloseFile

INVOKE Str_copy, ADDR buffer, addr content
INVOKE Str_length, ADDR content
mov esi, eax
mov content[esi],' '
inc esi
mov content[esi],'z'
inc esi
mov content[esi],' '
inc esi

mov ecx,lengthof content
mov esi,0
mov al,target
counttWords:
 cmp content[esi],al
 jne inccountt
 inc countt
  inccountt:
    inc esi
 loop counttWords 
mov eax,0

mov ecx,0
mov cl,countt
mov esi,0

l2:
 mov tcx,ecx
 INVOKE Str_length, ADDR content
 mov ecx,eax
 mov eax,0
 dec ecx
 mov al,target
 mov esi,0
 mov start,0
 mov end1,0

 call empty_temp
 

 l1: 
   cmp content[esi],al
   je l3
   inc esi
 loop l1

 
mov ecx,tcx
 cmp ecx,1
 ja con
 jmp del
 con:
 call concat
 del:
 call delete


loop l2

call exi


l3:
mov end1,esi
call tokenize
INVOKE Str_compare, ADDR temp, addr smallest
jb calc
jmp el
calc:
call calc_min

el:
inc esi
dec ecx
jmp l1


exi:
mov edx,offset fileee1
call writestring
call crlf

mov edx , OFFSET filename2
call CreateOutputFile
mov fileHandle,eax

mov eax,fileHandle
mov edx,OFFSET ascending
mov ecx,lengthof ascending
call WriteToFile
call CloseFile

	call waitmsg
ret
CHARACTER_SORT_FILE Endp

WORD_SORT_FILE PROC

call clrscr

mov edx,offset fileee
call writestring
mov edx , OFFSET filename
call OpenInputFile
mov fileHandle,eax

mov edx,OFFSET buffer
mov ecx,BUFFER_SIZE
call ReadFromFile

INVOKE Str_length, ADDR Buffer
mov buffer[eax],0

mov edx,OFFSET buffer ; display the buffer
call WriteString
call Crlf

   mov num_word,0
   mov inn,0
   mov dl,13
   mov esi,offset buffer
   mov edi,offset array2D
   mov ebx,offset array_str

   
   INSERTING:
   mov eax,0
   cmp [esi],dl
   je nexes
   cmp [esi],eax
   je nexes
   mov al,[esi]
   mov [edi],al
   inc inn
   inc esi
   inc edi
   jmp newer
   nexes:
   sub edi,inn
   mov [ebx],edi
   inc num_word
   add ebx,4
   add edi,inn
   add edi,20
   inc esi
   inc esi
   mov inn,0
   newer:
   mov eax,0
   cmp [esi],eax
   jne INSERTING

   sub edi,inn
   mov [ebx],edi
   inc num_word
   
dec NUM_WORD ;NUMBER OF TIMES TO PERFORM SORT

       ; Strings are all loaded into memory, time to sort
BEGIN_SORT:
       MOV swap, 0                       ; Flag for if we make a swap this pass
       MOV EAX, 0                        ; Current string in str_array

COMPARE_LOOP:
; Loads two string addresses to compare into registers
       MOV EDX, [array_str + EAX * 4]   
       INC EAX
       MOV ECX, [array_str + EAX * 4]

       MOV EBX, 0                        ; Initial location in string
STR_CMP:
; Pull off a byte from the string and load it into EDI
       MOVZX EDI, BYTE PTR [EDX + EBX]         

; If we hit the end of the first string here, assume we are less than the other string
CMP EDI, 0
       JE LESS_THAN
       MOVZX ESI, BYTE PTR [ECX + EBX] ; Same thing, but for ESI
       CMP ESI, 0           ; If we hit the end of the second string here, assume we are greater than
       JE GREATER_THAN
       CMP EDI, ESI         ; Else we just do a comparison on the ASCII value of the indexed character in the string
       JL LESS_THAN
       JG GREATER_THAN
       INC EBX              ; Both characters are equal, move to the next one in the strings and do it again
       JMP STR_CMP
LESS_THAN:
       JMP CHECK_END_SORT   ; If the first string is less than the second, they are in order, no swapping needed
GREATER_THAN:
       DEC EAX
       MOV [array_str + EAX * 4], ECX
       INC EAX
       MOV [array_str + EAX * 4], EDX ; Swap entries
       MOV swap, 1
CHECK_END_SORT:
       CMP EAX,NUM_WORD
       JNE COMPARE_LOOP     ; We are not at the end of str_array yet, loop again with next two elements

       ; If we are here, we are at end of str_array
       CMP [swap], 0
       JNE BEGIN_SORT       ; If we made a swap in this pass of str_array, do another pass from the very beginning

       ; END OF SORTING

	   ;WRITING SORTED STRING
	   call crlf
	   inc NUM_WORD
 
	   mov edx,offset fileee1
	   call writestring
	   call crlf

mov edx , OFFSET filename2
call CreateOutputFile
mov fileHandle,eax

mov eax,fileHandle

MOV ECX,NUM_WORD	; Number of strings to write on file
       MOV ESI,0		; Current string to write on file

WRITE_SORTED_WORDS_In_FILE:
       mov ebx,ecx 
	   MOV EDX, [array_str + ESI * 4]
	   INVOKE Str_length,EDX
	   mov ecx,eax
	   mov eax,fileHandle
	   CALL WriteToFile
	   mov eax,fileHandle
	   mov ecx,1
	   mov edx,offset CRR
	   call WriteToFile
	   mov eax,fileHandle
	   mov ecx,1
	   mov edx,offset LF
	   call WriteToFile
	   mov ecx,ebx
       INC ESI
       LOOP WRITE_SORTED_WORDS_IN_FILE

call CloseFile




mov eax,0
mov ecx,1000
mov edi,offset array2D
DONE12:
mov [edi],eax
inc edi
LOOP DONE12

mov ecx,100
mov edi,offset array_str
DON:
MOV [edi],eax
inc edi
LOOP DON


call crlf
call waitmsg
ret
WORD_SORT_FILE ENDP


SORT_STRING_FILE PROC
local tcx:dword

call clrscr
mov edx,offset fileee
call writestring
mov edx , OFFSET filename
call OpenInputFile
mov fileHandle,eax

mov edx,OFFSET buffer
mov ecx,BUFFER_SIZE
call ReadFromFile

mov buffer[eax],0

mov edx,OFFSET buffer ; display the buffer
call WriteString
call Crlf

mov eax,fileHandle
call CloseFile

INVOKE Str_copy, ADDR buffer, addr content
INVOKE Str_length, ADDR content
mov esi, eax
mov content[esi],' '
inc esi
mov content[esi],'z'
inc esi
mov content[esi],' '
inc esi

mov ecx,lengthof content
mov esi,0
mov al,target
counttWords:
 cmp content[esi],al
 jne inccountt
 inc countt
  inccountt:
    inc esi
 loop counttWords 
mov eax,0

mov ecx,0
mov cl,countt
mov esi,0

l2:
 mov tcx,ecx
 INVOKE Str_length, ADDR content
 mov ecx,eax
 mov eax,0
 dec ecx
 mov al,target
 mov esi,0
 mov start,0
 mov end1,0

 call empty_temp
 

 l1: 
   cmp content[esi],al
   je l3
   inc esi
 loop l1

 
mov ecx,tcx
 cmp ecx,1
 ja con
 jmp del
 con:
 call concat
 del:
 call delete


loop l2

call exi


l3:
mov end1,esi
call tokenize
INVOKE Str_compare, ADDR temp, addr smallest
jb calc
jmp el
calc:
call calc_min

el:
inc esi
dec ecx
jmp l1


exi:
mov edx,offset fileee1
call writestring
call crlf

mov edx , OFFSET filename2
call CreateOutputFile
mov fileHandle,eax

mov eax,fileHandle
mov edx,OFFSET ascending
mov ecx,lengthof ascending
call WriteToFile
call CloseFile


ret
SORT_STRING_FILE  ENDP

calc_min proc
INVOKE Str_copy, ADDR temp, addr smallest
ret 
calc_min endp


tokenize proc

 local tempecx:dword , tempesi:dword, tempal:dword,result:dword

mov tempecx,ecx
mov tempesi,esi
mov tempal,eax
push edi
INVOKE Str_length, ADDR temp

mov ecx,16
mov edi,0
l2:
mov al,temp[edi]
xor temp[edi],al
inc edi
loop l2



mov edi,0
mov ecx,end1
mov esi,start


sub ecx,start


l4:
mov al,content[esi]
mov temp[edi],al
inc edi
inc start
inc esi
loop l4

inc start
;mov edx,offset temp
;call writestring 
;call crlf

mov eax,tempal
mov esi,tempesi
mov ecx,tempecx
pop edi
ret
tokenize endp

concat PROC
local tempecx:dword , tempesi:dword, tempal:dword

mov tempecx,ecx
mov tempesi,esi
mov tempal,eax
push edi

INVOKE Str_length, ADDR smallest

mov ecx,eax
mov eax,0
mov edi,current
;call dumpregs
mov esi,0
l1:
mov al,smallest[esi]
mov ascending[edi],al
inc esi
inc edi
inc current
loop l1

mov al,target
mov ascending[edi],al
;inc esi
;inc edi
inc current

;mov edi,offset ascending
;call writestring
;call crlf

mov eax,tempal
mov esi,tempesi
mov ecx,tempecx
pop edi

ret
concat endp

delete proc
local tempecx:dword , tempesi:dword, tempal:dword, index1:dword ,lensmall:dword, subtr:dword

mov tempecx,ecx
mov tempesi,esi
mov tempal,eax
push edi

INVOKE Str_length, ADDR smallest
mov lensmall,eax
mov esi,0
mov edi,0


  mov al,smallest[edi]
  mov ecx,lengthof content
  l1:
    cmp al,content[esi]
    je comp
    inc esi
  loop l1
  jmp exitttt

 comp: 
 mov index1,esi
   push ecx
   push esi
   push edi
   push eax

   mov edi,0
   mov subtr,ecx
   mov esi,index1
   mov ecx,lensmall
   cmp ecx,subtr
   jbe l2
   jmp back

   l2:
    mov al,smallest[edi]
    cmp al,content[esi]
    jne back
	inc esi
	inc edi
   loop l2
   jmp afterfound

   back:
    pop eax
    pop edi
    pop esi
	pop ecx

    inc esi
    dec ecx
    jmp l1

	afterfound:
	 mov esi,index1
	 add esi,lensmall
	 mov al,target
	 cmp content[esi],al
	 jne back
     
	 beforefound:
	  mov esi,index1
	  cmp esi,0
	  je found
	  dec esi
	  mov al,target
	  cmp content[esi],al
	  jne back

	found:
	 mov eax,index1
	 ;call writeint
	 ;call crlf
	 mov esi,index1
	 mov al,content[esi]
	 ;call writechar
	 ;call crlf
    pop eax
    pop edi
    pop esi
	pop ecx
	jmp actual
  
  actual:
  mov eax,lensmall
  add eax,index1
  mov lensmall,eax
  mov ecx,lengthof content
  sub ecx,lensmall
  ;call dumpregs
    mov esi,lensmall
  mov edi,index1
  inc esi
  
   l3:
   mov al,content[esi]
    mov content[edi],al
   inc esi
   inc edi
   loop l3
   
   mov al,target
   mov content[edi],al
   inc edi
   
   INVOKE Str_length, ADDR smallest
   mov ecx,eax
   mov eax,0
   l4:
   mov al,content[edi]
   xor content[edi],al
   inc edi
   loop l4
 ; mov edx,offset content
  ;call writestring
 INVOKE Str_length, ADDR content
 ;call dumpregs
exitttt:
mov eax,tempal
mov esi,tempesi
mov ecx,tempecx
pop edi
ret
delete endp

empty_temp proc
local tempecx:dword , tempesi:dword, tempal:dword, index1:dword ,lensmall:dword, subtr:dword

mov tempecx,ecx
mov tempesi,esi
mov tempal,eax
mov ecx, 16

mov esi,0
l1:
mov al, temp[esi]
xor temp[esi],al
inc esi
loop l1

mov ecx,16
mov esi,0
l2:
mov smallest[esi],'z'
inc esi
loop l2

mov eax,tempal
mov esi,tempesi
mov ecx,tempecx

ret
empty_temp endp


end main