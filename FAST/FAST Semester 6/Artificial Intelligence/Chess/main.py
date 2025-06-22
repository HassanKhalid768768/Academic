import ChessGame as ce
import chess as ch
import sys
import time

class Main:
    def __init__(self, board=None):
        if board is None:
            self.board = ch.Board()
        else:
            self.board = board

    def print_board(self):
        # Using the display dictionary with uniform formatting for all cells
        display = {
            None: " . ",  # Empty square with spaces to match the width of piece symbols
            "B": " ♝",
            "K": " ♚",
            "N": " ♞",
            "P": " ♟",
            "Q": " ♛",
            "R": " ♜",
            "b": " ♗",
            "k": " ♔",
            "n": " ♘",
            "p": " ♙",
            "q": " ♕",
            "r": " ♖",
        }
        print("  a  b  c  d  e  f  g  h")
        print(" +----------------------------+")
        for rank in range(8, 0, -1):
            row = f"{rank}|"
            for file in range(8):
                piece = self.board.piece_at(ch.square(file, rank - 1))
                row += display[piece.symbol() if piece else None]
            row += f" |{rank}"  # Ensure consistent spacing before the rank number on the right
            print(row)
        print(" +----------------------------+")
        print("  a  b  c  d  e  f  g  h\n")
    def play_human_move(self):
        while True:
            self.print_board()
            print("Available commands: [move] e.g., 'e2e4', 'undo', 'quit'")
            print("Legal moves:", ', '.join([move.uci() for move in self.board.legal_moves]))
            play = input("Your move (SAN): ").strip().lower()

            if play == "undo":
                if len(self.board.move_stack) >= 2:
                    self.board.pop()
                    self.board.pop()
                else:
                    print("\033[91mNo moves to undo!\033[0m")
                continue
            elif play == "quit":
                sys.exit()
            try:
                self.board.push_san(play)
                break
            except ValueError:
                print("\033[91mInvalid move, please try again.\033[0m")


    def play_engine_move(self, max_depth, color):
        print("The engine is thinking...")
        engine = ce.Engine(self.board, max_depth, color)
        move = engine.getBestMove()
        if move:
            print(f"Engine chooses to move: {move.uci()}")  # Diagnostic print
            self.board.push(move)
            self.print_board()
        else:
            print("No valid moves available for the engine, or engine returned no move.")
            self.print_board() 

    def start_game(self):
        # Set up the player and engine colors
        color = None
        while color not in ["b", "w"]:
            color = input("Play as white (w) or black (b): ")

        max_depth = None
        while not isinstance(max_depth, int):
            try:
                max_depth = int(input("Choose engine depth: "))
            except ValueError:
                print("Please enter a valid number.")

        engine_color = ch.WHITE if color == 'b' else ch.BLACK
        player_color = ch.BLACK if color == 'w' else ch.WHITE

        # Adjust starting turn
        self.board.turn = player_color

        # Track time spent by player and engine
        player_time = 0
        engine_time = 0

        while not self.board.is_game_over():
            if self.board.turn == player_color:
                start_time = time.time()  # Start tracking player's time
                self.play_human_move()  # Execute the human's move
                end_time = time.time()  # End tracking
                player_time += end_time - start_time
                print(f"Player's total time: {player_time:.2f} seconds")
            else:
                start_time = time.time()  # Start tracking engine's time
                self.play_engine_move(max_depth, engine_color)  # Execute the engine's move
                end_time = time.time()
                engine_time += end_time - start_time
                print(f"Engine's total time: {engine_time:.2f} seconds")

        self.print_board()  # Final board state
        print("Game over! Result:", self.board.outcome())

        # Ask if the player wants to start again
        play_again = input("Play again? (y/n): ")
        if play_again.lower() == 'y':
            self.board.reset()
            self.start_game()

def main():
    game = Main()
    game.start_game()

if __name__ == "__main__":
    main()