$(document).ready(function (){   
    var sideslider = $('[data-toggle=collapse-side]');
    var sel = sideslider.attr('data-target');
    var sel2 = sideslider.attr('data-target-2');
    sideslider.click(function(event){
    $(sel).toggleClass('in');
    $(sel2).toggleClass('out');
    });
});

$(document).ready(function() {
    const $valueSpan = $('.valueSpan');
    const $value = $('#slider11');
    $valueSpan.html($value.val());
    $value.on('input change', () => {
  
      $valueSpan.html($value.val());
    });
  });