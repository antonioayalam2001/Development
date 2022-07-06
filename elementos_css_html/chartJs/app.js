const labels = [
    'January',
    'February',
    'March',
    'April',
    'May',
    'June',
];

const data = {
    labels: labels,
    datasets: [{
        label: 'My First dataset',
        backgroundColor: [
            'rgb(255, 99, 132)',
            'rgb(54, 162, 235)',
            'rgb(255, 205, 86)',
            'rgb(25, 105, 86)',
            'rgb(5, 205, 86)',
            'rgb(255, 5, 6)'
        ],
        borderColor: 'rgb(255, 255, 255)',
        data: [20, 10, 5, 2, 20, 30],
    }]
};

const config = {
    type: 'line',
    data: data,
    options: {
        animations: {
            radius: {
                duration: 400,
                easing: 'linear',
                loop: (context) => context.active
            }
        },
        hoverRadius: 12,
        hoverBackgroundColor: 'black',
        interaction: {
            mode: 'nearest',
            intersect: false,
            axis: 'x'
        },
        plugins: {
            tooltip: {
                enabled: false
            },
            title: {
                display: true,
                text: (ctx) => 'Titulo de la grafica',
            }
            
        }
    },};

const myChart = new Chart(
    document.getElementById('myChart'),
    config
);