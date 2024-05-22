import { configureStore } from '@reduxjs/toolkit';
import ledReducer from './ledSlice';

export default configureStore({
  reducer: {
    led: ledReducer,
  },
});
