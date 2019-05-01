[org 7C00h]

start:
    mov ah, 06h
    mov al, 0
    mov bh, 43h
    int 10h

    ; TODO: Going to stage2

times 510 - ($ - start) db 0
dw 0AA55h