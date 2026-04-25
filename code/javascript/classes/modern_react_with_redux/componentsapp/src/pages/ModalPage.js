import { useState } from "react";
import Modal from "../components/Modal";
import Button from "../components/Button";

function ModalPage() {
  const [showModal, setShowModal] = useState(false);

  const handleClick = () => {
    setShowModal(true);
  };

  const handleClose = () => {
    setShowModal(false);
  };

  const actionBar = (
    <div>
      <Button onClick={handleClose} primary>
        I understand!
      </Button>
    </div>
  );
  const modal = (
    <Modal onClose={handleClose} actionBar={actionBar}>
      <p>Here is an important message!</p>
    </Modal>
  );

  return (
    <div>
      <Button onClick={handleClick} primary>
        Open Modal
      </Button>
      {showModal && modal}

      <p>
        Etiam sagittis quam ligula, lobortis sollicitudin sapien vestibulum sed.
        Integer vehicula, augue sed finibus sagittis, sem nulla pharetra purus,
        in hendrerit eros magna vitae est. Lorem ipsum dolor sit amet,
        consectetur adipiscing elit. Etiam venenatis, velit ac condimentum
        vehicula, eros tellus posuere turpis, vitae efficitur arcu enim ac urna.
        Aenean sagittis, eros et elementum semper, diam risus accumsan nulla,
        vel imperdiet mi arcu vel magna. Maecenas facilisis sapien sed elit
        fermentum, ut pellentesque orci consequat. Nam lobortis nisl vitae eros
        finibus dictum. Quisque eu nisi justo. Nullam sagittis eget nibh feugiat
        lacinia. Integer vestibulum quam leo, at ultrices purus interdum vel.
        Fusce rutrum, neque vitae bibendum gravida, augue tortor luctus ligula,
        ac pellentesque dui velit a sem. Nulla ut congue tortor. Sed feugiat
        ante pretium, commodo enim eu, tincidunt velit. Donec pulvinar accumsan
        ante, sit amet pharetra nulla finibus vel. Maecenas finibus tellus non
        purus suscipit scelerisque. Donec diam felis, interdum id diam at,
        ultricies lacinia lorem.
      </p>
      <p>
        Etiam sagittis quam ligula, lobortis sollicitudin sapien vestibulum sed.
        Integer vehicula, augue sed finibus sagittis, sem nulla pharetra purus,
        in hendrerit eros magna vitae est. Lorem ipsum dolor sit amet,
        consectetur adipiscing elit. Etiam venenatis, velit ac condimentum
        vehicula, eros tellus posuere turpis, vitae efficitur arcu enim ac urna.
        Aenean sagittis, eros et elementum semper, diam risus accumsan nulla,
        vel imperdiet mi arcu vel magna. Maecenas facilisis sapien sed elit
        fermentum, ut pellentesque orci consequat. Nam lobortis nisl vitae eros
        finibus dictum. Quisque eu nisi justo. Nullam sagittis eget nibh feugiat
        lacinia. Integer vestibulum quam leo, at ultrices purus interdum vel.
        Fusce rutrum, neque vitae bibendum gravida, augue tortor luctus ligula,
        ac pellentesque dui velit a sem. Nulla ut congue tortor. Sed feugiat
        ante pretium, commodo enim eu, tincidunt velit. Donec pulvinar accumsan
        ante, sit amet pharetra nulla finibus vel. Maecenas finibus tellus non
        purus suscipit scelerisque. Donec diam felis, interdum id diam at,
        ultricies lacinia lorem.
      </p>
      <p>
        Etiam sagittis quam ligula, lobortis sollicitudin sapien vestibulum sed.
        Integer vehicula, augue sed finibus sagittis, sem nulla pharetra purus,
        in hendrerit eros magna vitae est. Lorem ipsum dolor sit amet,
        consectetur adipiscing elit. Etiam venenatis, velit ac condimentum
        vehicula, eros tellus posuere turpis, vitae efficitur arcu enim ac urna.
        Aenean sagittis, eros et elementum semper, diam risus accumsan nulla,
        vel imperdiet mi arcu vel magna. Maecenas facilisis sapien sed elit
        fermentum, ut pellentesque orci consequat. Nam lobortis nisl vitae eros
        finibus dictum. Quisque eu nisi justo. Nullam sagittis eget nibh feugiat
        lacinia. Integer vestibulum quam leo, at ultrices purus interdum vel.
        Fusce rutrum, neque vitae bibendum gravida, augue tortor luctus ligula,
        ac pellentesque dui velit a sem. Nulla ut congue tortor. Sed feugiat
        ante pretium, commodo enim eu, tincidunt velit. Donec pulvinar accumsan
        ante, sit amet pharetra nulla finibus vel. Maecenas finibus tellus non
        purus suscipit scelerisque. Donec diam felis, interdum id diam at,
        ultricies lacinia lorem.
      </p>
      <p>
        Etiam sagittis quam ligula, lobortis sollicitudin sapien vestibulum sed.
        Integer vehicula, augue sed finibus sagittis, sem nulla pharetra purus,
        in hendrerit eros magna vitae est. Lorem ipsum dolor sit amet,
        consectetur adipiscing elit. Etiam venenatis, velit ac condimentum
        vehicula, eros tellus posuere turpis, vitae efficitur arcu enim ac urna.
        Aenean sagittis, eros et elementum semper, diam risus accumsan nulla,
        vel imperdiet mi arcu vel magna. Maecenas facilisis sapien sed elit
        fermentum, ut pellentesque orci consequat. Nam lobortis nisl vitae eros
        finibus dictum. Quisque eu nisi justo. Nullam sagittis eget nibh feugiat
        lacinia. Integer vestibulum quam leo, at ultrices purus interdum vel.
        Fusce rutrum, neque vitae bibendum gravida, augue tortor luctus ligula,
        ac pellentesque dui velit a sem. Nulla ut congue tortor. Sed feugiat
        ante pretium, commodo enim eu, tincidunt velit. Donec pulvinar accumsan
        ante, sit amet pharetra nulla finibus vel. Maecenas finibus tellus non
        purus suscipit scelerisque. Donec diam felis, interdum id diam at,
        ultricies lacinia lorem.
      </p>
      <p>
        Etiam sagittis quam ligula, lobortis sollicitudin sapien vestibulum sed.
        Integer vehicula, augue sed finibus sagittis, sem nulla pharetra purus,
        in hendrerit eros magna vitae est. Lorem ipsum dolor sit amet,
        consectetur adipiscing elit. Etiam venenatis, velit ac condimentum
        vehicula, eros tellus posuere turpis, vitae efficitur arcu enim ac urna.
        Aenean sagittis, eros et elementum semper, diam risus accumsan nulla,
        vel imperdiet mi arcu vel magna. Maecenas facilisis sapien sed elit
        fermentum, ut pellentesque orci consequat. Nam lobortis nisl vitae eros
        finibus dictum. Quisque eu nisi justo. Nullam sagittis eget nibh feugiat
        lacinia. Integer vestibulum quam leo, at ultrices purus interdum vel.
        Fusce rutrum, neque vitae bibendum gravida, augue tortor luctus ligula,
        ac pellentesque dui velit a sem. Nulla ut congue tortor. Sed feugiat
        ante pretium, commodo enim eu, tincidunt velit. Donec pulvinar accumsan
        ante, sit amet pharetra nulla finibus vel. Maecenas finibus tellus non
        purus suscipit scelerisque. Donec diam felis, interdum id diam at,
        ultricies lacinia lorem.
      </p>
      <p>
        Etiam sagittis quam ligula, lobortis sollicitudin sapien vestibulum sed.
        Integer vehicula, augue sed finibus sagittis, sem nulla pharetra purus,
        in hendrerit eros magna vitae est. Lorem ipsum dolor sit amet,
        consectetur adipiscing elit. Etiam venenatis, velit ac condimentum
        vehicula, eros tellus posuere turpis, vitae efficitur arcu enim ac urna.
        Aenean sagittis, eros et elementum semper, diam risus accumsan nulla,
        vel imperdiet mi arcu vel magna. Maecenas facilisis sapien sed elit
        fermentum, ut pellentesque orci consequat. Nam lobortis nisl vitae eros
        finibus dictum. Quisque eu nisi justo. Nullam sagittis eget nibh feugiat
        lacinia. Integer vestibulum quam leo, at ultrices purus interdum vel.
        Fusce rutrum, neque vitae bibendum gravida, augue tortor luctus ligula,
        ac pellentesque dui velit a sem. Nulla ut congue tortor. Sed feugiat
        ante pretium, commodo enim eu, tincidunt velit. Donec pulvinar accumsan
        ante, sit amet pharetra nulla finibus vel. Maecenas finibus tellus non
        purus suscipit scelerisque. Donec diam felis, interdum id diam at,
        ultricies lacinia lorem.
      </p>
      <p>
        Etiam sagittis quam ligula, lobortis sollicitudin sapien vestibulum sed.
        Integer vehicula, augue sed finibus sagittis, sem nulla pharetra purus,
        in hendrerit eros magna vitae est. Lorem ipsum dolor sit amet,
        consectetur adipiscing elit. Etiam venenatis, velit ac condimentum
        vehicula, eros tellus posuere turpis, vitae efficitur arcu enim ac urna.
        Aenean sagittis, eros et elementum semper, diam risus accumsan nulla,
        vel imperdiet mi arcu vel magna. Maecenas facilisis sapien sed elit
        fermentum, ut pellentesque orci consequat. Nam lobortis nisl vitae eros
        finibus dictum. Quisque eu nisi justo. Nullam sagittis eget nibh feugiat
        lacinia. Integer vestibulum quam leo, at ultrices purus interdum vel.
        Fusce rutrum, neque vitae bibendum gravida, augue tortor luctus ligula,
        ac pellentesque dui velit a sem. Nulla ut congue tortor. Sed feugiat
        ante pretium, commodo enim eu, tincidunt velit. Donec pulvinar accumsan
        ante, sit amet pharetra nulla finibus vel. Maecenas finibus tellus non
        purus suscipit scelerisque. Donec diam felis, interdum id diam at,
        ultricies lacinia lorem.
      </p>
      <p>
        Etiam sagittis quam ligula, lobortis sollicitudin sapien vestibulum sed.
        Integer vehicula, augue sed finibus sagittis, sem nulla pharetra purus,
        in hendrerit eros magna vitae est. Lorem ipsum dolor sit amet,
        consectetur adipiscing elit. Etiam venenatis, velit ac condimentum
        vehicula, eros tellus posuere turpis, vitae efficitur arcu enim ac urna.
        Aenean sagittis, eros et elementum semper, diam risus accumsan nulla,
        vel imperdiet mi arcu vel magna. Maecenas facilisis sapien sed elit
        fermentum, ut pellentesque orci consequat. Nam lobortis nisl vitae eros
        finibus dictum. Quisque eu nisi justo. Nullam sagittis eget nibh feugiat
        lacinia. Integer vestibulum quam leo, at ultrices purus interdum vel.
        Fusce rutrum, neque vitae bibendum gravida, augue tortor luctus ligula,
        ac pellentesque dui velit a sem. Nulla ut congue tortor. Sed feugiat
        ante pretium, commodo enim eu, tincidunt velit. Donec pulvinar accumsan
        ante, sit amet pharetra nulla finibus vel. Maecenas finibus tellus non
        purus suscipit scelerisque. Donec diam felis, interdum id diam at,
        ultricies lacinia lorem.
      </p>
      <p>
        Etiam sagittis quam ligula, lobortis sollicitudin sapien vestibulum sed.
        Integer vehicula, augue sed finibus sagittis, sem nulla pharetra purus,
        in hendrerit eros magna vitae est. Lorem ipsum dolor sit amet,
        consectetur adipiscing elit. Etiam venenatis, velit ac condimentum
        vehicula, eros tellus posuere turpis, vitae efficitur arcu enim ac urna.
        Aenean sagittis, eros et elementum semper, diam risus accumsan nulla,
        vel imperdiet mi arcu vel magna. Maecenas facilisis sapien sed elit
        fermentum, ut pellentesque orci consequat. Nam lobortis nisl vitae eros
        finibus dictum. Quisque eu nisi justo. Nullam sagittis eget nibh feugiat
        lacinia. Integer vestibulum quam leo, at ultrices purus interdum vel.
        Fusce rutrum, neque vitae bibendum gravida, augue tortor luctus ligula,
        ac pellentesque dui velit a sem. Nulla ut congue tortor. Sed feugiat
        ante pretium, commodo enim eu, tincidunt velit. Donec pulvinar accumsan
        ante, sit amet pharetra nulla finibus vel. Maecenas finibus tellus non
        purus suscipit scelerisque. Donec diam felis, interdum id diam at,
        ultricies lacinia lorem.
      </p>
      <p>
        Etiam sagittis quam ligula, lobortis sollicitudin sapien vestibulum sed.
        Integer vehicula, augue sed finibus sagittis, sem nulla pharetra purus,
        in hendrerit eros magna vitae est. Lorem ipsum dolor sit amet,
        consectetur adipiscing elit. Etiam venenatis, velit ac condimentum
        vehicula, eros tellus posuere turpis, vitae efficitur arcu enim ac urna.
        Aenean sagittis, eros et elementum semper, diam risus accumsan nulla,
        vel imperdiet mi arcu vel magna. Maecenas facilisis sapien sed elit
        fermentum, ut pellentesque orci consequat. Nam lobortis nisl vitae eros
        finibus dictum. Quisque eu nisi justo. Nullam sagittis eget nibh feugiat
        lacinia. Integer vestibulum quam leo, at ultrices purus interdum vel.
        Fusce rutrum, neque vitae bibendum gravida, augue tortor luctus ligula,
        ac pellentesque dui velit a sem. Nulla ut congue tortor. Sed feugiat
        ante pretium, commodo enim eu, tincidunt velit. Donec pulvinar accumsan
        ante, sit amet pharetra nulla finibus vel. Maecenas finibus tellus non
        purus suscipit scelerisque. Donec diam felis, interdum id diam at,
        ultricies lacinia lorem.
      </p>
    </div>
  );
}

export default ModalPage;
