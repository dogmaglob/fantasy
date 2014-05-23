#ifndef __BOARD_H__
#define __BOARD_H__

typedef struct _board board;

board * board_new();
void    board_destroy(board * b);
void    board_draw(board * b);

#endif //__BOARD_H__
