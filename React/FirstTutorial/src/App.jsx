import { useState } from 'react'
import { useEffect } from 'react'
import logo from './logo.svg'
import './App.css'



// UseRef()



// UseEffect()



// <>    Un tag vacío nos indica un Fragment  </>



const CheckFunction =  () => { console.log("Running"); return 23}
function App() {
  const [count, setCount] = useState(0)
  // Todo el cuerpo de la funcion APP se ejecuta cada vez que se quiera hacer un render en el DOM
  // UseState puede recibir dos cosas
  // Lo que quiera que se guarde en el estado
  // Una funcion que se ejecuta cuando se quiera actualizar el estado
//  SetCount es una funcion que se ejecuta cuando se quiera actualizar el estado (dado el estado actual ) => que le debe pasar 
  const Gretter = ({age,name }) => { 
    if (name === 'Sara') {
      return <h1>Hello Sara</h1>
    } else { 
      return <h1>Hello {name} your age is {age}</h1>
    }
  }

const [car, setCar] = useState({
    brand: "Ford",
    model: "Mustang",
    year: "1964",
    color: "red"
})
  
    const updateColor = () => {
    setCar(previousState => {
      return { ...previousState, year: "1992" }
    });
    }
  
    const [calculation, setCalculation] = useState(10);

  useEffect(() => {
    setCalculation(() => count * 2);
  }, [car]); // <- add the count variable here
  


  return (
    <div className="App">
      <header className="App-header">
        <img src={logo} className="App-logo" alt="logo" />
        <p>Hello Vite + React!</p>
        <p>The count is { count}</p>
        <p>
          <button type="button" onClick={() => setCount( count + 1)}>
            ++
          </button>
          <button type="button" onClick={() => setCount(count - 1)}>
            --
          </button>

        </p>

          <p>Calculation: {calculation}</p>
      </header>
      <div>
        <Gretter age={32} name={count > 3 ? "Alicia" : "Jose" }></Gretter>
        <Gretter age={ 32} name="Antonio"></Gretter>
        <Gretter age={ 32} name="Mom"></Gretter>
      </div>

      <p>{car.color}</p>
      <p>{car.year}</p>
      
      <button onClick={ updateColor}>Da click</button>

    </div>

  )
}

export default App
