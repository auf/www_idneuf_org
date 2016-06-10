jQuery(document).ready(function ($) {
    
    $('.form-xml2node-submit').click(function() {
        $(this).toggleClass('checked');
        if($(this).hasClass('checked')) {
            $('.xml2node-report').find(':checkbox').attr('checked', true);
        } else {
            $('.xml2node-report').find(':checkbox').attr('checked', false);
        }
        return false;
    });
})