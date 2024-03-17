const totalImages = 28;
let currentSlide = 0;

function updateImageSource() {
    const carouselInner = document.querySelector('.carousel-inner');
    const newImageNumber = (currentSlide % totalImages) + 1;
    const newImagePath = `/static/assets/slider-photo/${newImageNumber}.jpg`;

    const currentActive = carouselInner.querySelector('.active');

    const newImage = document.createElement('img');
    newImage.classList.add('d-block', 'w-100', 'h-50');
    newImage.src = newImagePath;
    newImage.alt = `Slide ${newImageNumber}`;

    currentActive.innerHTML = '';
    currentActive.appendChild(newImage);
}

document.querySelector('.carousel-control-next').addEventListener('click', () => {
    currentSlide++;
    updateImageSource();
});

document.querySelector('.carousel-control-prev').addEventListener('click', () => {
    currentSlide--;

    if (currentSlide < 0) {
        currentSlide = totalImages - 1;
    }

    updateImageSource();
});

updateImageSource();
