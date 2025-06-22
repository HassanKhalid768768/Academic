import chess as ch
import random as rd

class Engine:
    def __init__(self, board, maxDepth, color):
        self.board = board
        self.color = color
        self.maxDepth = maxDepth

    def getBestMove(self):
        return self.engine(-float('inf'), float('inf'), 1)

    def evalFunct(self):
        """ Evaluate the board using material sum, position evaluations, and additional heuristics. """
        totalValue = 0
        for i in range(64):
            totalValue += self.squareResPoints(ch.SQUARES[i])
        totalValue += self.mateOpportunity() + self.opening() + 0.001 * rd.random()
        return totalValue

    def mateOpportunity(self):
        """ Provide a large negative or positive score if the game is in a checkmate state. """
        if self.board.is_checkmate():
            return -999 if self.board.turn == self.color else 999
        return 0

    def opening(self):
        """ Encourage opening development. """
        if self.board.fullmove_number < 10:
            legalMovesCount = self.board.legal_moves.count()
            return 1/30 * legalMovesCount if self.board.turn == self.color else -1/30 * legalMovesCount
        return 0

    def squareResPoints(self, square):
        """ Calculate the material value of a piece at a given square adjusted for the engine's color perspective. """
        piece = self.board.piece_at(square)
        if not piece:
            return 0
        valueMap = {ch.PAWN: 1, ch.ROOK: 5.1, ch.BISHOP: 3.33, ch.KNIGHT: 3.2, ch.QUEEN: 8.8}
        pieceValue = valueMap.get(piece.piece_type, 0)
        return -pieceValue if piece.color != self.color else pieceValue

    def engine(self, alpha, beta, depth):
        if depth == 0:
            return self.evalFunct()
        elif depth == self.maxDepth or self.board.is_game_over():
            return self.evalFunct()

        bestValue = float('-inf') if self.board.turn == self.color else float('inf')
        bestMove = None
        for move in self.board.legal_moves:
            self.board.push(move)
            value = -self.engine(-beta, -alpha, depth + 1) if self.board.turn == self.color else self.engine(alpha, beta, depth + 1)
            self.board.pop()

            if self.board.turn == self.color:
                if value > bestValue:
                    bestValue = value
                    bestMove = move
                alpha = max(alpha, value)
            else:
                if value < bestValue:
                    bestValue = value
                    bestMove = move
                beta = min(beta, value)

            if alpha >= beta:
                break

        return bestMove if depth == 1 else bestValue