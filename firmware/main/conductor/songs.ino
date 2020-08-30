/* 
// This file is subject to the terms and conditions defined in
// file 'LICENSE.md', which is part of this source code package.
*/

#define SONG_ELEMENTS (STAFF_COLS*STAFF_ROWS)
#define SONG_IND_TO_ROW(I) (I % STAFF_COLS)
#define SONG_IND_TO_COL(I) (STAFF_ROWS - ((I / STAFF_COLS) + 1))

const staff_data_t T = INSTRUMENT_TRUMPET;
const staff_data_t F = INSTRUMENT_FLUTE;
//const staff_data_t D = INSTRUMENT_DRUM;
const staff_data_t P = INSTRUMENT_PIANO;
const staff_data_t G = INSTRUMENT_GUITAR;
const staff_data_t N = STAFF_VAL_NONE;

int row, col;

void playSong(staff_data_t* song){
  for(size_t idx = 0; idx < SONG_ELEMENTS; idx++){
      row = SONG_IND_TO_ROW(idx);
      col = SONG_IND_TO_COL(idx);
      staff[col][row] = song[idx];
    }
    
  DEBUG_PORT.println("Put song into staff");
//  static uint8_t prev_players = 0;
//  static uint8_t curr_players = 0;
//
//  AudioPlaySdWav* players = notePlayersAlpha;
//  prev_players = curr_players;
//  if(curr_players == 0x01){
//    players = notePlayersBeta;
//    curr_players = 0x00;
//  }else if(curr_players == 0x00){
//    curr_players = 0x01;
//  }
//  for(size_t colIndex = 0; colIndex < STAFF_COLS; colIndex++){
//    DEBUG_PORT.print("Iterating through Column: ");
//    DEBUG_PORT.println(colIndex);
//      for(size_t note = 0; note < STAFF_ROWS; note++){//Checks each row
//        DEBUG_PORT.print("Iterating through Row: ");
//        DEBUG_PORT.println(note);
//        staff_data_t instrument = staff[col][note]; //Assigns an instrument based on whats at that row and column
//        DEBUG_PORT.print("Instruments assigned: ");
//        DEBUG_PORT.println(instrument);
//        const char* filename = " NONE ";
//    
//    }
//    players[note].stop();
//    if(instrument != STAFF_VAL_NONE){
//       DEBUG_PORT.println("playing a note");
//       filename = SOUND(instrument, note);
//       players[note].play(filename);
//       delay(5); // A brief delay for the library read WAV info
//       }
//     delay(500);
}

//void show_song(staff_data_t* song){
//  for(size_t idx = 0; idx < SONG_ELEMENTS; idx++){
//    row = SONG_IND_TO_ROW(idx);
//    col = SONG_IND_TO_COL(idx);
//
//    CRGB color(0, 0, 0);
//
//    switch(song[idx]){
//      case STAFF_VAL_RED : color = CRGB(255, 0, 0); break;
//      case STAFF_VAL_YELLOW : color = CRGB(255,255,0); break;
//      case STAFF_VAL_GREEN : color = CRGB(0, 255, 0); break;
//      case STAFF_VAL_BLUE : color = CRGB(0, 0, 255); break;
//      case STAFF_VAL_CYAN : color = CRGB(0, 255, 255); break;
//      
//
//      default :
//      case STAFF_VAL_NONE :
//        // color already set to black
//        break;
//    }
//
//
////    setNodeRGB(col, row, color);
//  }
//}



staff_data_t clearStaff[SONG_ELEMENTS] = {
/*           0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15 */
/* 6 (B) */  N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N,
/* 5 (A) */  N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N,
/* 4 (G) */  N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N,
/* 3 (F) */  N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N,
/* 2 (E) */  N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N,
/* 1 (D) */  N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N,
/* 0 (C) */  N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, 
};

staff_data_t axelf[SONG_ELEMENTS] = {
/*           0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15 */
/* 6 (B) */  N, N, N, N, N, N, N, N, N, N, T, N, N, N, T, N,
/* 5 (A) */  N, N, N, N, N, T, T, N, N, N, N, N, N, N, N, N,
/* 4 (G) */  N, N, T, N, N, N, N, N, N, N, N, N, N, N, N, T,
/* 3 (F) */  N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N,
/* 2 (E) */  T, N, N, N, T, N, N, N, T, N, N, N, T, N, N, N,
/* 1 (D) */  N, N, N, N, N, N, N, T, N, N, N, N, N, N, N, N,
/* 0 (C) */  N, N, N, N, N, N, N, N, N, N, N, N, N, T, N, N, 
};

staff_data_t pokemonLevelUp[SONG_ELEMENTS] = {
/*           0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15 */
/* 6 (B) */  N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N,
/* 5 (A) */  N, N, N, N, N, N, N, N, G, G, G, N, N, N, N, N,
/* 4 (G) */  G, N, N, N, G, G, G, N, N, N, N, N, N, G, G, G,
/* 3 (F) */  N, G, N, G, N, N, N, N, N, N, N, N, N, N, N, N,
/* 2 (E) */  N, N, G, N, N, N, N, N, N, N, N, N, N, N, N, N,
/* 1 (D) */  N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N,
/* 0 (C) */  N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, 
};

staff_data_t funkytown[SONG_ELEMENTS] = {
/*           0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15 */
/* 6 (B) */  N, N, N, N, N, N, N, N, N, N, F, N, N, N, N, N,
/* 5 (A) */  N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N,
/* 4 (G) */  F, F, N, F, N, N, N, N, F, N, N, F, N, N, N, N,
/* 3 (F) */  N, N, F, N, N, N, N, N, N, N, N, N, N, N, N, N,
/* 2 (E) */  N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N,
/* 1 (D) */  N, N, N, N, N, F, N, F, N, N, N, N, N, N, N, N,
/* 0 (C) */  N, N, N, N, N, N, N, N, N, F, N, N, N, N, N, N, 
};

staff_data_t miiShopChannel[SONG_ELEMENTS] = {
/*           0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15 */
/* 6 (B) */  N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N,
/* 5 (A) */  N, N, P, N, N, P, N, N, N, N, N, N, N, N, N, N,
/* 4 (G) */  N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N,
/* 3 (F) */  P, N, N, N, N, N, N, P, N, N, N, N, N, N, N, N,
/* 2 (E) */  N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N,
/* 1 (D) */  N, N, N, P, N, N, N, N, P, P, P, N, N, N, N, N,
/* 0 (C) */  N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, 
};

staff_data_t somewhereOverTheRainbow[SONG_ELEMENTS] = {
/*           0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15 */
/* 6 (B) */  N, N, N, N, N, N, N, N, F, N, N, N, F, N, N, N,
/* 5 (A) */  N, N, N, N, N, N, N, N, N, N, N, F, N, N, N, N,
/* 4 (G) */  F, N, N, N, N, N, N, N, N, N, F, N, N, N, N, N,
/* 3 (F) */  N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N,
/* 2 (E) */  N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N,
/* 1 (D) */  N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N,
/* 0 (C) */  N, N, N, N, F, N, N, N, N, N, N, N, N, N, F, N, 
};

staff_data_t jurassicPark[SONG_ELEMENTS] = {
/*           0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15 */
/* 6 (B) */  T, N, T, N, N, N, N, N, T, N, T, N, N, N, N, N,
/* 5 (A) */  N, T, N, N, N, N, N, N, N, T, N, N, N, N, N, N,
/* 4 (G) */  N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N,
/* 3 (F) */  N, N, N, N, T, N, N, N, N, N, N, N, T, N, N, N,
/* 2 (E) */  N, N, N, N, N, N, T, N, N, N, N, N, N, N, T, N,
/* 1 (D) */  N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N,
/* 0 (C) */  N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, 
};

//void clear_song(void){
//  show_song(clearStaff);
//}
