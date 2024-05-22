import React from 'react';
import { useSelector, useDispatch } from 'react-redux';
import { toggleLed } from './redux/ledSlice';

function App() {
  const dispatch = useDispatch();
  const ledState = useSelector((state) => state.led.state);

  const handleToggle = () => {
    const newState = ledState === 0 ? 1 : 0;
    dispatch(toggleLed(newState));
  };

  return (
    <div>
      <h1>Arduino LED Toggle</h1>
      <button onClick={handleToggle}>
        {ledState === 0 ? 'Turn LED On' : 'Turn LED Off'}
      </button>
    </div>
  );
}

export default App;
