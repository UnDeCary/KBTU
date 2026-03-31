INSERT INTO public.blocks (page_id, type, position, content, styles, is_active) VALUES ( 1, 'hero', 1, '{"title": "making\nsomething\nnew", "bg_mobile": "/assets/imgs/hero/background_mobile.png", "bg_desktop": "/assets/imgs/hero/background.png"}', '{}', true);
INSERT INTO public.blocks (page_id, type, position, content, styles, is_active) VALUES ( 2, 'hero', 1, '{"title": "BArni: питает\nлюбознательность", "bg_mobile": "/assets/imgs/hero/background_product_mobile.png", "bg_desktop": "/assets/imgs/hero/background_product.png"}', '{}', true);
INSERT INTO public.blocks (page_id, type, position, content, styles, is_active) VALUES ( 2, 'promo', 2, '{"title": "Каждый bArni — это\nмаленькое удовольствие\nв кармане"}', '{}', true);
INSERT INTO public.blocks (page_id, type, position, content, styles, is_active) VALUES ( 2, 'flavors', 3, '{"title": "Мягкий бисквит\nс любимой наЧинкой", "products": [{"name": "Бисквитные пирожные\n«Медвежонок Barni»\nс шоколадной начинкой", "image": "/assets/imgs/flavors/chocolate-flover.png"}, {"name": "Бисквитные пирожные\n«Медвежонок Barni»\nс бананово-йогуртной начинкой", "image": "/assets/imgs/flavors/banana-flover.png"}, {"name": "Бисквитные пирожные\n«Медвежонок Barni»\nс молочной начинкой", "image": "/assets/imgs/flavors/milk-flover.png"}], "description": "Шоколад, молоко или банан-йогурт — выбирайте свой вкус Barni\nдля перекуса в любое время!"}', '{}', true);

Select * from global_blocks;


INSERT INTO public.global_blocks (language_id, type, content, styles) VALUES ( 1, 'header', '{"logo": "/assets/imgs/header/logo.png", "links": [{"url": "/en/main", "label": "Main"}]}', '{}');
INSERT INTO public.global_blocks (language_id, type, content, styles) VALUES ( 1, 'footer', '{"logo": "/assets/imgs/footer_logo.png", "instagram": {"url": "https://www.instagram.com/barnigeo", "logo": "/assets/imgs/social.png"}}', '{}');
INSERT INTO public.global_blocks (language_id, type, content, styles) VALUES ( 2, 'header', '{"logo": "/assets/imgs/header/logo.png", "links": [{"url": "/ru/main", "label": "Главная"}]}', '{}');
INSERT INTO public.global_blocks (language_id, type, content, styles) VALUES ( 2, 'footer', '{"logo": "/assets/imgs/footer_logo.png", "instagram": {"url": "https://www.instagram.com/barni.kazakhstan", "logo": "/assets/imgs/social.png"}}', '{}');
