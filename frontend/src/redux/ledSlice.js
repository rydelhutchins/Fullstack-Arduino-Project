import { createSlice } from '@reduxjs/toolkit';
import axios from 'axios';

export const ledSlice = createSlice({
  name: 'led',
  initialState: { state: 0 },
  reducers: {
    setLedState: (state, action) => {
      state.state = action.payload;
    },
  },
});

export const { setLedState } = ledSlice.actions;

export const toggleLed = (state) => async (dispatch) => {
  try {
    await axios.post('http://192.168.68.57:8000/toggle_led', { state });
    dispatch(setLedState(state));
  } catch (error) {
    console.error(error);
  }
};

export default ledSlice.reducer;
