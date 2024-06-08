// scanner.h
#ifndef scanner_h
#define scanner_h

typedef enum {
    // single-character tokens
    TOKEN_LEFT_PAREN, TOKEN_RIGHT_PAREN,		// '(', ')'
    TOKEN_LEFT_BRACKET, TOKEN_RIGHT_BRACKET,	// '[', ']'
    TOKEN_LEFT_BRACE, TOKEN_RIGHT_BRACE,  		// '{', '}'
    TOKEN_COMMA, TOKEN_DOT, TOKEN_SEMICOLON,	// ',', '.', ';'
    TOKEN_TILDE,  // '~'
    // one or two character tokens
    TOKEN_PLUS, TOKEN_PLUS_PLUS, TOKEN_PLUS_EQUAL, // '+', '++', '+='
    // '-', '--', '-=', '->'
    TOKEN_MINUS, TOKEN_MINUS_MINUS, TOKEN_MINUS_EQUAL, TOKEN_MINUS_GREATER,
    TOKEN_STAR, TOKEN_STAR_EQUAL,			// '*', '*='
    TOKEN_SLASH, TOKEN_SLASH_EQUAL, 		// '/', '/=', 
    TOKEN_PERCENT, TOKEN_PERCENT_EQUAL, 	// '%', '%='
    TOKEN_AMPER, TOKEN_AMPER_EQUAL, TOKEN_AMPER_AMPER, 	// '&', '&=', '&&'
    TOKEN_PIPE, TOKEN_PIPE_EQUAL, TOKEN_PIPE_PIPE,		// '|', '|=', '||'
    TOKEN_HAT, TOKEN_HAT_EQUAL, 		// '^', '^='
    TOKEN_EQUAL, TOKEN_EQUAL_EQUAL, 	// '=', '=='
    TOKEN_BANG, TOKEN_BANG_EQUAL,	  	// '!', '!='
    TOKEN_LESS, TOKEN_LESS_EQUAL, TOKEN_LESS_LESS, 				// '<', '<=', '<<'
    TOKEN_GREATER, TOKEN_GREATER_EQUAL, TOKEN_GREATER_GREATER, 	// '>', '>=', '>>'
    // �����⣺'>>=', '<<='
// ����ֵ: ��ʶ��, �ַ�, �ַ���, ����
TOKEN_IDENTIFIER, TOKEN_CHARACTER, TOKEN_STRING, TOKEN_NUMBER,
// �ؼ���
TOKEN_SIGNED, TOKEN_UNSIGNED,
TOKEN_CHAR, TOKEN_SHORT, TOKEN_INT, TOKEN_LONG,
TOKEN_FLOAT, TOKEN_DOUBLE,
TOKEN_STRUCT, TOKEN_UNION, TOKEN_ENUM, TOKEN_VOID,
TOKEN_IF, TOKEN_ELSE, TOKEN_SWITCH, TOKEN_CASE, TOKEN_DEFAULT,
TOKEN_WHILE, TOKEN_DO, TOKEN_FOR,
TOKEN_BREAK, TOKEN_CONTINUE, TOKEN_RETURN, TOKEN_GOTO,
TOKEN_CONST, TOKEN_SIZEOF, TOKEN_TYPEDEF,
// ����Token
TOKEN_ERROR, TOKEN_EOF
} TokenType;

typedef struct {
    TokenType type;
    const char* start;	// startָ��source�е��ַ���sourceΪ�����Դ���롣
    int length;		    // length��ʾ���Token�ĳ���
    int line;		    // line��ʾ���Token��Դ�������һ��, �������ı���
    // �����⣺int column;
} Token;

// �� Scanner ���г�ʼ�� 
void initScanner(const char* source);

// ����scanToken(), ������һ��Token.
Token scanToken();

#endif