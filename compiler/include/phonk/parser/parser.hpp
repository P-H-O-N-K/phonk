//
// Created by Maxwell Morgan on 9/6/26.
//

#ifndef PHONK_PARSER_HPP
#define PHONK_PARSER_HPP

#include <span>
#include <phonk/diagnostics/diagnostic_engine.hpp>
#include <phonk/lexer/token.hpp>

namespace phonk::parser {

struct ParserOptions {
    // TODO: Decide parser options & implement
};

class Parser {
public:
    /**
     * Initializes a new Parser.
     *
     * @param tokens Vector containing tokenized source code.
     * @param diagnosticEngine The diagnostic engine to use (default: nullptr).
     * @param options Extraneous options for lexer (default: {}).
     */
    explicit Parser(std::vector<lexer::Token> tokens,
                    diagnostics::DiagnosticEngine* diagnosticEngine = nullptr,
                    ParserOptions options = {});

private:
    std::span<const lexer::Token> tokens_;
    int pos_ = 0;

    diagnostics::DiagnosticEngine* diagnosticEngine_;
    ParserOptions options_;


};

}

#endif //PHONK_PARSER_HPP