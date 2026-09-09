//
// Created by Maxwell Morgan on 9/6/26.
//

#include <phonk/parser/parser.hpp>

namespace phonk::parser {

Parser::Parser(std::vector<lexer::Token> tokens, diagnostics::DiagnosticEngine* diagnosticEngine,
               const ParserOptions options)
    : tokens_(tokens), diagnosticEngine_(diagnosticEngine), options_(options) {
}

}